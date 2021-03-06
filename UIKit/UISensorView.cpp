/****************************************************************************
	Cocos  Project
			hosting	github.com
Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include <UIKit/UISensorView.h>
#include <NIKit/NIDevice.h>
#include <UIKit/UIImage.h>
#define super UIView
UISensorView*
	UISensorView::init()
{
	if(super::init())
	{
	self->device =  NIDevice::sharedDevice();
	UIImage* image =  
		UIImage::imageWithData_format_pixel_size(
		device->rawRGBData(),CCTexture2DPixelFormat::kCCTexture2DPixelFormat_RGB888,CCSizeMake(640,480));
	self->node = CCSprite::spriteWithTexture(image->getCCTexture2D());
	self->node->setPosition(ccp(320,240));
	}
	return self;
}
void 
	UISensorView::updateFromDevice()
{
	self->device->update();
	CCSprite* sprite = (CCSprite*) self->node ;
	sprite->getTexture()->release();
	CCTextureCache::sharedTextureCache()->removeUnusedTextures();
	UIImage* image =  
		UIImage::imageWithData_format_pixel_size(
		device->rawRGBData(),CCTexture2DPixelFormat::kCCTexture2DPixelFormat_RGB888,CCSizeMake(640,480));
	sprite->setTexture(image->getCCTexture2D());
}
void
	UISensorView::dealloc()
{
	self->node->release();
	self->node = nil;
}