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
#pragma once
#include <QuartzCore/QuartzCore.h>
#include <UIKit/UIGestureRecognizer.h>
NS_CLASS UIEvent;
NS_INTERFACE(UILongPressGestureRecognizer , UIGestureRecognizer)
	UILongPressGestureRecognizer*
		initWithTarget_action(NSActionTarget* ,SEL_PP);
	virtual void 
		 touchesBegan_withEvent(NSSet* touches ,UIEvent* events);
	 virtual void 
		 touchesMoved_withEvent(NSSet* touches ,UIEvent* events);
	 virtual void 
		 touchesEnded_withEvent(NSSet* touches ,UIEvent* events);
protected:
	NS_SYNTHESIZE 
		(NSUInteger ,numberOfTapsRequired );
	NS_SYNTHESIZE 
		(NSUInteger ,numberOfTapsAcquired );
	NS_SYNTHESIZE 
		(NSTimeInterval ,tapStartTime );
	NS_SYNTHESIZE 
		(CGFloat ,tapStartX );
	NS_SYNTHESIZE 
		(CGFloat ,tapStartY );
NS_END