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
#include <UIKit/UILongPressGestureRecognizer.h>
#include <UIKit/UITouch.h>
#define super UIGestureRecognizer
UILongPressGestureRecognizer*
	UILongPressGestureRecognizer::initWithTarget_action(NSActionTarget* ctarget ,SEL_PP cselector)
{
	if(super::init())
	{
		self->m_pListener = ctarget;
		self->m_pSelector = cselector;
		self->tapStartTime = 0;
	}
	return self;
}
void
	UILongPressGestureRecognizer::touchesBegan_withEvent(NSSet* touches ,UIEvent* events)
{
	self->state = UIGestureRecognizerStatePossible;
	if(super::dependenceCheck())
	{
		self->tapStartTime = ((UITouch*) touches->anyObject())->gettimeMark();
	}else{
		self->state  = UIGestureRecognizerStateFailed;
	}
}
void
	UILongPressGestureRecognizer::touchesMoved_withEvent(NSSet* touches ,UIEvent* events)
{

}
void
	UILongPressGestureRecognizer::touchesEnded_withEvent(NSSet* touches ,UIEvent* events)
{
	if(super::dependenceCheck() && self->state == UIGestureRecognizerStatePossible )
	{
	NSTimeInterval endTime = ((UITouch*) touches->anyObject())->gettimeMark();
	NSTimeInterval timediff = endTime -  self->tapStartTime ;
	if(timediff < 0.0001)
	{
		self->state  = UIGestureRecognizerStateFailed;
		return ;
	}
	if( timediff > 0.003f && timediff < 5.0f)
	{
		self->state = UIGestureRecognizerStateRecognized;
		(self->m_pListener->*m_pSelector)(nil,self);
	}else{
		self->state  = UIGestureRecognizerStateFailed;
	}
	}
}
void
	UILongPressGestureRecognizer::dealloc()
{
}