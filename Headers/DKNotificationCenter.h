/** Interface for DKNotificationCenter to handle D-Bus signals.
   Copyright (C) 2010 Free Software Foundation, Inc.

   Written by:  Niels Grewe <niels.grewe@halbordnung.de>
   Created: August 2010

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

#import <Foundation/NSObject.h>
#import <DBusKit/DKPort.h>
@class DKEndpoint, DKProxy, NSDictionary, NSLock, NSMutableDictionary, NSNotification, NSString;

@interface DKNotificationCenter: NSObject
{
  /**
   * The endpoint object used by the notification center to communicate with
   * D-Bus.
   */
  DKEndpoint *endpoint;

  /**
   * The dispatch tables relating observers and signals observed.
   */
  void *dispatchTables;

  /**
   * The signalInfo dictionary holds DKSignal objects indexed by their interface
   * and signal names. Proxies that discover signals during introspection will
   * register them here.
   */
  NSMutableDictionary *signalInfo;

  /**
   * The lock protecting the table.
   */
   NSLock *lock;
}

+ (id)sessionBusCenter;

+ (id)systemBusCenter;

+ (id)centerForBusType: (DKDBusBusType)type;

- (void)addObserver: (id)observer
           selector: (SEL)notifySelector
               name: (NSString*)notificationName
	     object: (DKProxy*)sender;

-  (void)addObserver: (id)observer
            selector: (SEL)notifySelector
              signal: (NSString*)signalName
           interface: (NSString*)interfaceName
              object: (DKProxy*)sender
   filtersAndIndices: (NSString*)firstFilter, NSUInteger firstindex, ...;

- (void)removeObserver: (id)observer;

- (void)removeObserver: (id)observer
                  name: (NSString*)notificationName
                object: (DKProxy*)sender;

- (void)removeObserver: (id)observer
                signal: (NSString*)signalName
             interface: (NSString*)interfaceName
                object: (DKProxy*)sender;

- (void)postNotification: (NSNotification*)notification;

- (void)postNotificationName: (NSString*)name
                      object: (id)sender;

- (void)postSignalName: (NSString*)signalName
             interface: (NSString*)interfaceName
                object: (id)sender;

- (void)postNotificationName: (NSString*)name
                      object: (id)sender
                    userInfo: (NSDictionary*)info;

- (void)postSignalName: (NSString*)signalName
             interface: (NSString*)interfaceName
                object: (id)sender
              userInfo: (NSDictionary*)info;

- (BOOL)registerNotificationName: (NSString*)notificationName
                        asSignal: (NSString*)signalName
                     inInterface: (NSString*)interface;
@end
