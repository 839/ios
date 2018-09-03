#ifndef MACROS.H
#define MACROS.H
#if TARGET_IPHONE_SIMULATOR//模拟器
#define PHONE_MARK  0
#elif TARGET_OS_IPHONE//真机
#define PHONE_MARK 1
#endif

//16进制颜色转换
#define UIColorFromRGB(rgbValue) [UIColor colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 green:((float)((rgbValue & 0xFF00) >> 8))/255.0 blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

//屏幕的宽高
#define SCREEN_WIDTH   [[UIScreen mainScreen] bounds].size.width
#define SCREEN_HEIGHT  [[UIScreen mainScreen] bounds].size.height
/**
 *  按比例获取尺寸(相对5，5s的屏幕宽度)
 *
 *  @param pxValue 尺寸
 *
 *  @return float
 */
#define GetFloatWithPX(pxValue) pxValue/320.0*SCREEN_WIDTH
/**
 *  按5，5s的屏幕高度获取相对尺寸
 *
 *  @param pxValue 尺寸
 *
 *  @return float
 */
#define GetFloatContrastHightWithPX(pxValue) pxValue/568.0*SCREEN_HEIGHT

CG_INLINE CGRect
CGRectMakeContrastWidth(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = GetFloatWithPX(x); rect.origin.y = GetFloatWithPX(x);
    rect.size.width = GetFloatWithPX(width); rect.size.height = GetFloatWithPX(height);
    return rect;
}

CG_INLINE CGRect
CGRectMakeContrastHight(CGFloat x, CGFloat y, CGFloat width, CGFloat height)
{
    CGRect rect;
    rect.origin.x = GetFloatContrastHightWithPX(x); rect.origin.y = GetFloatContrastHightWithPX(x);
    rect.size.width = GetFloatContrastHightWithPX(width); rect.size.height = GetFloatContrastHightWithPX(height);
    return rect;
}

CG_INLINE CGSize
CGSizeMakeContrastWidth(CGFloat width, CGFloat height)
{
    CGSize size;
    size.width = GetFloatWithPX(width);
    size.height = GetFloatWithPX(height);
    return size;
}
CG_INLINE CGSize
CGSizeMakeContrastHight(CGFloat width, CGFloat height)
{
    CGSize size;
    size.width = GetFloatContrastHightWithPX(width);
    size.height = GetFloatContrastHightWithPX(height);
    return size;
}
//转化为weak对象（block循环引用使用时）
#define WeakObj(o) __weak typeof(o) obj##Weak = o;

#define DEBUGGER 1 //上线版本屏蔽此宏

#ifdef DEBUGGER
/* 自定义log 可以输出所在的类名,方法名,位置(行数)*/
#define VDLog(format, ...) NSLog((@"%s [Line %d] " format), __FUNCTION__, __LINE__, ##__VA_ARGS__)

#else

#define VDLog(...)

#endif

#endif
