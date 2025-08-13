//
//  SPDatabaseConnection.h
//  sequel-ace
//
//  Created by Sequel Ace Development Team on December 2024
//  Copyright (c) 2024 Moballo, LLC. All rights reserved.

#import <Foundation/Foundation.h>

/**
 * Protocol that defines the common interface for database connections
 * that can be used by SPDatabaseDocument
 */
@protocol SPDatabaseConnection <NSObject>

@required

// Connection state
- (BOOL)isConnected;
- (BOOL)isConnectedViaSSL;
- (BOOL)userTriggeredDisconnect;
- (void)disconnect;

// Server information  
- (NSUInteger)serverMajorVersion;
- (NSUInteger)serverMinorVersion;
- (NSUInteger)serverReleaseVersion;

// Database operations
- (NSArray *)databases;
- (NSString *)database;
- (void)selectDatabase:(NSString *)aDatabase;

// Query execution
- (id)queryString:(NSString *)theQueryString;
- (id)streamingQueryString:(NSString *)theQueryString;

// Error information
- (NSUInteger)queryErrorID;
- (NSString *)queryErrorMessage;

// Connection details
- (NSString *)host;
- (NSString *)user;
- (NSUInteger)port;

@end