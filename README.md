# iOSHardwareDecoder

iOS hardware decoder demo

这是iOS硬解码 H.264 视频的例子

AAPLEAGLLayer.m 是用OpenGL渲染 YUV的Layer，我从苹果例子里抄的

VideoFileParser.m 是个很简陋的264文件的解析，只是用来做例子，不要模仿

ViewController.m 重点看这里，演示了VideoToolbox的API如何调用

注意几点：

iOS解码器接受的Nal数据需要MP4格式的，就是在每个包头的前4字节放Big－endian的size，而不是00 00 00 01的startcode，需要转换下。

初始化解码器用的sps pps数据是不包括startcode的。

解码播放后的视频会抖动，这就对了，因为视频里是有B－frame的，iOS解码器不负责重排B帧顺序，需要应用自己根据PTS去做。
