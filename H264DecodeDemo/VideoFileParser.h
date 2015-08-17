#include <objc/NSObject.h>

@interface VideoPacket : NSObject

@property uint8_t* buffer;
@property NSInteger size;

@end

@interface VideoFileParser : NSObject

-(BOOL)open:(NSString*)fileName;
-(VideoPacket *)nextPacket;
-(void)close;

@end
