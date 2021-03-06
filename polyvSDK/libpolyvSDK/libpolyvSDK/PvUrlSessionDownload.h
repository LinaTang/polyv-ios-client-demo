
#import <Foundation/Foundation.h>
#import "PvUrlSessionDownloadDelegate.h"
/**
 *  新版SDK下载API
 */
@interface PvUrlSessionDownload : NSObject<NSURLSessionDataDelegate,NSURLSessionDownloadDelegate>

@property (nonatomic, strong) NSDictionary *videoInfo;
@property (nonatomic, copy)void(^completeBlock)(void);  // ***此代码块必须实现回调，具体参见demo中的使用


@property int level;

//+ (id)sharedInstance;

/**
 *  初始化视频信息
 *
 *  @param vid   视频vid
 *  @param level 视频清晰度，1是流畅，2是高清，3是超清
 *
 */
- (instancetype)initWithVid:(NSString*)vid level:(int)level;

/** 设置是否在后台*/
- (void)setBackgroundMode:(BOOL)isBackground;

/**停止或暂停下载*/
-(void)stop;

/** 是否已经停止下载 **/
-(BOOL)isStoped;

/**开始下载*/
- (void)start;

/**设置下载代理回调*/
-(void)setDownloadDelegate:(id<PvUrlSessionDownloadDelegate>)delegate;

/**删除某个码率视频文件*/
+(void)deleteVideo:(NSString*)vid;

/**删除某个视频所有码率文件*/
+(void)deleteVideo:(NSString*)vid level:(int)level;

/**设置视频下载目录不备份到icloud*/
-(BOOL)addSkipBackupAttributeToDownloadedVideos;

/**删除所有下载文件*/
-(void)cleanDownload;

/**某个清晰度的视频是否存在*/
+(BOOL)isVideoExists:(NSString*)vid level:(int)level;

/**取消下载会话*/
-(void)cleanSession;

@end

