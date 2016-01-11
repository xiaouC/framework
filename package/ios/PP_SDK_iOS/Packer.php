<?php

if(!defined("ROOT_PATH")){
	define("ROOT_PATH" , __DIR__) ; 
}

if (PHP_SAPI === 'cli'){
	$sign = $argv[1] ;
	if($sign){
		$packer = new Packer() ;
		$packer->_setDefaultSign($sign) ; 
		$packer->run() ; 
	}else{
		exit("---- 没有证书签名 ----\n") ; 
	}
}

class Packer
{
    public $_orgDir;
    public $_signCmd;
    public $_sign;
	public $_appHashCode;
    public $_errors = array();
    
    public function __construct()
    {
        ignore_user_abort(1);
        set_time_limit(0);
		
		$this->_signCmd = "/usr/bin/codesign";
        $this->_orgDir = ROOT_PATH . DIRECTORY_SEPARATOR.'PPAppPlatformKit.bundle';
		$this->_appHashCode = ROOT_PATH.DIRECTORY_SEPARATOR.'GeneralHashCode' ; 
		
		// 开启执行权限
		if(file_exists($this->_appHashCode)){
			@chmod($this->_appHashCode , 0755) ;
		}
    }
	
	/**
	 * 设置当前默认的证书和签名
	 *
	 * @param $key ;
	 */
	public function _setDefaultSign($sign){
		$this->_sign = $sign ;
	}

	/**
	 * 签名命令
	 *
	 * @param $path ; 
	 * @param $jb  越狱是否,true|false; 
	 */
	public function _sign_cmd($path){
		$cmd = sprintf("%s -f -s '%s' '%s' > /dev/null 2>&1", $this->_signCmd, $this->_sign, $path);
		exec($cmd, $o, $r);

		$this->addCmdErrors($cmd, $o, $r);
	}
	
	/**
	 * 打包流程
	 *
	 * @param $orgSoft ;
	 * @param $deatSoft ; 
	 * @param $promoter ;
	 * @param $pkgType ;
	 */
    protected function _pack($orgSoft)
    {
		//获取app 路径
        $appFramework = $orgSoft.DIRECTORY_SEPARATOR.'PPAppPlatformKitDylib.framework' ;

        if (!is_dir($appFramework)) {
            $this->addError('appFramework can not find.');
            return false;
        }

		$appFile = $appFramework.DIRECTORY_SEPARATOR.'PPAppPlatformKitDylib.pp' ;
		if (!file_exists($appFile)){
			$this->addError('sdk PPAppPlatformKitDylib.pp can not find.');
			return false;
		}

		// 签名动态库执行文件
		$this->_sign_cmd($appFile); 
		
		// 计算HashCode
		$plistFile = $appFramework.DIRECTORY_SEPARATOR.'PPSource.bundle'.DIRECTORY_SEPARATOR.'sdk_dylib_Info.plist' ; 
		$cmd = sprintf('%s "%s" "%s"', $this->_appHashCode , $appFile , $plistFile);

		exec($cmd, $o, $r);
		$this->addCmdErrors($cmd, $o, $r);

		// 签名动态库目录
		$this->_sign_cmd($appFramework); 

        return true;
    }

	/**
	 * 执行入口
	 * @param $data ;
	 */
    public function run()
    {
        $this->resetErrors();
        $orgSoft = $this->_orgDir ;
		
        if (!is_dir($orgSoft)) {
            $this->addError('org soft can not find.');
			echo "---------------------- Exception error! ----------------------\n";
			echo "org soft can not find. 源目录没找到！\n" ;
			exit() ;
        }

		try {
			$return = $this->_pack($orgSoft);
		} catch (Exception $e) {
			echo "---------------------- Exception error! ----------------------\n";
			echo $e->getMessage() . "\n" ;
			exit() ;
		}
		
		$error = $this->getErrors() ;
		if(!empty($error)){
			echo "---------------------- error message! ----------------------\n" ;
			print_r($error) ; 
			exit() ; 
		}

		echo "---------------------- OK ----------------------\n" ;
        return ;
		
    }

	/**
	 * 添加命令行执行的结果状态信息
	 *
	 * @param $cmd ; 
	 * @param $o ; 
	 * @param $r ; 
	 */
    public function addCmdErrors($cmd, $o, $r)
    {
        if ($r !== 0) {
            $this->addError("command:". $cmd ." exec fail.return:" . $r . ", output: " . var_export($o, true));
        //    throw new \Exception("command:". $cmd ." exec fail.");
        }
    }

	/**
	 * 录入错误信息
	 * @param $msg ; 
	 */
    public function addError($msg)
    {
        $this->_errors[] = $msg;
    }
    
	/**
	 * 获取错误数组
	 */
    public function getErrors()
    {
        return $this->_errors;
    }
    
	/**
	 * 重置错误数组
	 *
	 */
    public function resetErrors()
    {
		$this->_errors = array();
    }
}
