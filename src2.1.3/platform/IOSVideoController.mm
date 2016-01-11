#import "IOSVideoController.h"  
#import "AppController.h"  
@implementation IOSVideoController  
  
//播放网络视频  
-(void)playUrlVideo  
{  
  
  
  
}  
-(void)playVideo:(NSString *)filename :(CCLayer *)targetLayer  
{  
    TargetLayer =targetLayer;  
    //跳转Layer非空  
    if (targetLayer) {  
        TargetLayer->retain();  
    }  
  
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();  
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();  
  
    //NSString *myFilePath = [[NSBundle mainBundle] pathForResource:filename ofType:nil inDirectory:nil];  
    //NSURL *url = [NSURL fileURLWithPath:myFilePath];  
    NSURL *url = [NSURL fileURLWithPath:filename];  
      
    movePlayer=[[MPMoviePlayerController alloc] initWithContentURL:url];  
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(movieFinished:) name:MPMoviePlayerPlaybackDidFinishNotification object:movePlayer];  
      
    if([movePlayer respondsToSelector:@selector(setFullscreen:animated:)])  
    {  
        movePlayer.shouldAutoplay=YES;
        movePlayer.controlStyle = MPMovieControlStyleFullscreen;
        movePlayer.scalingMode = MPMovieScalingModeAspectFill;
        movePlayer.scalingMode = MPMovieScalingModeFill;
        
        /*
        CCSize winSize=CCDirector::sharedDirector()->getWinSize();
        CCSize frameSize = CCEGLView::sharedOpenGLView()->getFrameSize();

        // 这里iPad2和ipad3 视频位置调整是正确的，Iphone 可能需要细微调整  
        if ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPhone)  
        {  
            //movePlayer.view.frame=CGRectMake(-80,80, 480, 320);
            movePlayer.view.frame=CGRectMake(0,0, 480, 320);
        }  
        else if([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)  
        {  
            //movePlayer.view.frame=CGRectMake(-128, 128, winSize.width, winSize.height);
            movePlayer.view.frame=CGRectMake(0, 0, winSize.width + 64 * 2, winSize.height + 64 );
        }  
        else  
        {  
            //movePlayer.view.frame=CGRectMake(-80,80, 480, 320);
            movePlayer.view.frame=CGRectMake(0,0, 480, 320);
        }
        */
        
        UIWindow* keyWindow = [[UIApplication sharedApplication] keyWindow];
        [[movePlayer view] setFrame:CGRectMake(0, 0, keyWindow.frame.size.width, keyWindow.frame.size.height)];
        [[movePlayer view] setCenter: CGPointMake(keyWindow.center.x, keyWindow.center.y)];
        [movePlayer.view setTransform:CGAffineTransformMakeRotation(0)];
          
        ////        强制横屏
        //CGAffineTransform landscapeTransform;
        //UIDevice *device = [UIDevice currentDevice] ;
        //if (device.orientation==UIDeviceOrientationLandscapeLeft)
        //{
        //    landscapeTransform = CGAffineTransformMakeRotation(M_PI / 2);
        //}
        //else
        //{
        //    landscapeTransform = CGAffineTransformMakeRotation(-M_PI / 2);
        //}
        //movePlayer.view.transform = landscapeTransform;
          
        // 新建一个window，添加视频这个UIView  
        window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];  
          
        [window addSubview:movePlayer.view];  
        [window makeKeyAndVisible];
        
        ////  在视频上方添加“跳过”按钮
        //CGRect frame = CGRectMake(768-100, 100, 100, 50);
        //UIButton *button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
        //button.frame = frame;
        //[button setTitle:@"跳过" forState: UIControlStateNormal];
          
        ////button.transform =landscapeTransform;
        //button.backgroundColor = [UIColor clearColor];
        //button.tag = 2000;
        //[button addTarget:self action:@selector(buttonClicked:) forControlEvents:UIControlEventTouchUpInside];
        //[window addSubview:button];
          
  
        //  设置是否带控制条  
        //movePlayer.controlStyle = MPMovieControlStyleNone;  
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(exitFullScreen:) name:MPMoviePlayerDidExitFullscreenNotification object:nil];  
          
    }  
    else  
    {  
        //movePlayer.controlStyle=MPMovieControlModeHidden;  
    }  
      
    [self playMovie];  
  
  
}  
//跳过视频  
-(IBAction) buttonClicked:(id)sender {  
    [movePlayer stop];  
  
    [movePlayer.view removeFromSuperview];  
    [movePlayer release];  
    [window release];  
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();  
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();  
      
    if (!TargetLayer) {  
        return;  
    }  
    TargetLayer->removeAllChildrenWithCleanup(true);  
    TargetLayer->removeFromParent();  
  
    CCScene * scene =CCScene::create();  
    scene->addChild(TargetLayer,10);  
    CCDirector::sharedDirector()->replaceScene(scene);  
      
      
}  
//播放开始  
-(void) playMovie  
{  
    MPMoviePlaybackState state=movePlayer.playbackState;  
    if(state==MPMoviePlaybackStatePlaying)  
    {  
        NSLog(@"Movie is already playing.");  
        return;  
    }  
    [movePlayer play];  
}  
//退出全屏  
-(void)exitFullScreen:(NSNotification *)notification{  
    CCLOG("exitFullScreen");  
    movePlayer.controlStyle=MPMovieControlStyleDefault;  
    [movePlayer.view removeFromSuperview];  
}  
//视频播放结束  
- (void) movieFinished:(NSNotificationCenter *)notification{  
//    CCLOG("moviePlaybackFinished");  
    //视频播放完毕  
    
    movePlayer.controlStyle=MPMovieControlStyleDefault;  
    MPMoviePlaybackState state=movePlayer.playbackState;  
    if(state==MPMoviePlaybackStateStopped){  
        NSLog(@"Movie is already stopped.");  
        return;  
    }  
    [[NSNotificationCenter defaultCenter] removeObserver:self name:MPMoviePlayerPlaybackDidFinishNotification object:movePlayer];  
    if([movePlayer respondsToSelector:@selector(setFullscreen:animated:)])  
    {  
  
        [movePlayer.view removeFromSuperview];  
        [window release];  
          
        SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();  
        SimpleAudioEngine::sharedEngine()->resumeAllEffects();  
          
        if (!TargetLayer) {  
            return;  
        }  
        TargetLayer->removeAllChildrenWithCleanup(true);  
        TargetLayer->removeFromParent();  
        CCScene * scene =CCScene::create();  
        scene->addChild(TargetLayer,10);  
        CCDirector::sharedDirector()->replaceScene(scene);  
  
    }  
      
}  
  
- (void)dealloc {  
    [super dealloc];  
    if (TargetLayer) {  
            TargetLayer->release();  
    }  
  
}  
@end  
