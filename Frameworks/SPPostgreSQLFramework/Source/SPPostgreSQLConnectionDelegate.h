//
//  SPPostgreSQLConnectionDelegate.h
//  SPPostgreSQLFramework
//
//  Created by Sequel Ace Development Team on December 2024
//  Copyright (c) 2024 Moballo, LLC. All rights reserved.

#import <Foundation/Foundation.h>

@class SPPostgreSQLConnection;

@protocol SPPostgreSQLConnectionDelegate <NSObject>

@optional

/**
 * Notifies the delegate that a query will be performed.
 */
- (void)willQueryString:(NSString *)query connection:(SPPostgreSQLConnection *)connection;

/**
 * Notifies the delegate that the connection was lost.
 */
- (void)connectionLost:(SPPostgreSQLConnection *)connection;

/**
 * Requests the delegate whether the connection should reconnect when a connection error occurs.
 */
- (BOOL)connectionShouldReconnect:(SPPostgreSQLConnection *)connection;

@end