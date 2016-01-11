//
//  BlockAlertView.h
//  
//
//  Created by willonboy on 12-12-4.
//  Copyright (c) 2012年 willonboy.tk. All rights reserved.
//


/*
 USE LIKE :
 
 BlockAlertView *blockAlert = [BlockAlertView new];
 [blockAlert showAlertWithTitle:@"" msg:@"确定删除" callbackBlock:^(int btnIndex){
 
    if (btnIndex == 0)
    {
        return ;
    }
    else if(btnIndex == 1)
    {
        NSLog(@"正在删除");
    }
 
 } cancelButtonTitle:@"取消" otherButtonTitles:@"确定", nil];
 
 [blockAlert release];
 
 */


typedef void (^blockAlertViewCallBackBlock)(int btnIndex);


#import <Foundation/Foundation.h>

@interface BlockAlertView : NSObject


- (void)showAlertWithTitle:(NSString *)title msg:(NSString *)msg callbackBlock:(blockAlertViewCallBackBlock)block
         cancelButtonTitle:(NSString *)cancelBtnTitle otherButtonTitles:(NSString *)otherButtonTitles, ... ;

@end
