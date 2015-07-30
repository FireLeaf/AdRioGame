/**************************************************************************
/*		FileName: Platform.cpp
/*		FileDesc: 
/*		FileAuthor: YangCao
/*		CreateTime: 2015/07/30 19:48:39
/*		CopyRight: yc 
/*************************************************************************/

#include "PlatformIOS_US.h"
#import <FBSDKLoginKit/FBSDKLoginKit.h>

void OGPlatformIOSUS::Login(const char *szCommand)
{
    if (!szCommand) {
        return;
    }
    
    if (strcmp(szCommand, "facebook") == 0) {
        FBSDKLoginManager *login = [[FBSDKLoginManager alloc] init];
        login.loginBehavior = FBSDKLoginBehaviorWeb;
        [login logInWithReadPermissions:nil handler:^(FBSDKLoginManagerLoginResult *result, NSError *error) {
            if (error) {
                
            }
            else if (result.isCancelled)
            {
                [login logOut];
            }
            else
            {
                
            }
        }];
    }
}

void OGPlatformIOSUS::Logout(const char* szCommand)
{

}
