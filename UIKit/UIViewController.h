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
#include <Foundation/Foundation.h>
#include <UIKit/UIView.h>
#include <UIKit/UIResponder.h>
#include <NIKit/NIKit.h>
#include <UIKit/UIStoryboard.h>
NS_INTERFACE_INIT_SPEC( UIViewController ,  UIView )
NS_IGNORE UIViewController(){};
void
	loadView();
virtual void 
	viewDidLoad(void){}
void 
	viewDidUnload(void){}
void 
	viewDidRender(CCLayer* host );
virtual void 
	viewDidUpdate(cocos2d::CGFloat ){};
void 
	viewReloadData(NSMutableArray* toShow);

CCNode*  
	renderTargetforHost();
virtual void 
	touchesBegan_withEvent(NSSet* touches ,UIEvent* events);
virtual void 
	touchesMoved_withEvent(NSSet* touches ,UIEvent* events);
virtual void 
	touchesEnded_withEvent(NSSet* touches ,UIEvent* events) ;
virtual void 
	controller_torsoData(void* ,vid){};
virtual void 
	controller_righthandData(void* ,vid){};
virtual void 
	sender_torsoData(void* ,void*);
void
	retain();
void 
	release();
public:
	UIView* view;
	UIView* followView;
	UIView* clickView;
	UIView* watchVariableView;
	UIView* righthand_clicked_marker;
protected:
	bool isRighthandTracked;
	UITouchPhase menuTouchPhase;

	NS_SYNTHESIZE
		(CGFloat ,torsox);
	NS_SYNTHESIZE
		(CGFloat ,torsoy);
	NS_SYNTHESIZE_RETAIN_READONLY
		(UIStoryboard* ,storyboard);

	float touchStartx;
	float touchStarty;
	CGFloat touchStartTime;

	float t_lasthandx;
	float t_lasthandy;
	bool newTouchSession;

	UIView* receiver ;
	NS_SYNTHESIZE
		(NSString*,title);
NS_END