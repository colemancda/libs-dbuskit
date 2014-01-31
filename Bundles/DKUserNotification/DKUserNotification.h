/* Interface for DKUserNotification for GNUstep
   Copyright (C) 2014 Free Software Foundation, Inc.

   Written by:  Marcus Mueller <znek@mulle-kybernetik.com>
   Date: 2014

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Library General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the Free
   Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02111 USA.
*/

// NOTE: for the time being, NSUserNotificationCenter needs this feature.
// Whenever this restriction is lifted, we can get rid of it here as well.
#if __has_feature(objc_default_synthesize_properties)

#import <GNUstepBase/GSVersionMacros.h>

#if OS_API_VERSION(MAC_OS_X_VERSION_10_8,GS_API_LATEST)

#import <Foundation/NSUserNotification.h>

#if defined(__cplusplus)
extern "C" {
#endif

@class NSConnection, NSArray;
@protocol Notifications;

@interface DKUserNotificationCenter : NSUserNotificationCenter
{
  NSConnection *connection;
  id <NSObject, Notifications> proxy;
  NSArray *caps;
}

@end

#if defined(__cplusplus)
}
#endif

#endif /* OS_API_VERSION(MAC_OS_X_VERSION_10_8,GS_API_LATEST) */
#endif /* __has_feature(objc_default_synthesize_properties) */
