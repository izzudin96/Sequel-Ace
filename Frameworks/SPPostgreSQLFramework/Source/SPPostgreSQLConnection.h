//
//  SPPostgreSQLConnection.h
//  SPPostgreSQLFramework
//
//  Created by Sequel Ace Development Team on December 2024
//  Copyright (c) 2024 Moballo, LLC. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person
//  obtaining a copy of this software and associated documentation
//  files (the "Software"), to deal in the Software without
//  restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the
//  Software is furnished to do so, subject to the following
//  conditions:
//
//  The above copyright notice and this permission notice shall be
//  included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
//  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
//  OTHER DEALINGS IN THE SOFTWARE.

#import <Foundation/Foundation.h>
#import "SPPostgreSQLConnectionDelegate.h"
#import "SPPostgreSQLConstants.h"

@interface SPPostgreSQLConnection : NSObject {
    
    // Delegate
    __weak NSObject <SPPostgreSQLConnectionDelegate> *delegate;
    BOOL delegateSupportsWillQueryString;
    BOOL delegateSupportsConnectionLost;
    BOOL delegateQueryLogging;
    
    // Basic connection details
    NSString *host;
    NSString *username;
    NSString *password;
    NSUInteger port;
    BOOL useSocket;
    NSString *socketPath;
    
    // SSL connection details
    BOOL useSSL;
    NSString *sslKeyFilePath;
    NSString *sslCertificatePath;
    NSString *sslCACertificatePath;
    
    // PostgreSQL connection details and state
    void *pgConnection; // PGconn* pointer
    SPPostgreSQLConnectionState state;
    BOOL connectedWithSSL;
    BOOL userTriggeredDisconnect;
    
    // Currently selected database
    NSString *database;
    
    // Timeout settings
    NSUInteger timeout;
    
    // Encoding details
    NSString *encoding;
    NSStringEncoding stringEncoding;
    
    // Server details
    NSString *serverVariableVersion;
    NSUInteger serverVersionNumber;
    
    // Error state for the last query or connection state
    NSUInteger queryErrorID;
    NSString *queryErrorMessage;
    
    // Query details
    unsigned long long lastQueryAffectedRowCount;
    
    // Timing details
    uint64_t lastConnectionUsedTime;
    double lastQueryExecutionTime;
    
    // Queries
    BOOL retryQueriesOnConnectionFailure;
}

#pragma mark -
#pragma mark Synthesized properties

@property (readwrite, copy) NSString *host;
@property (readwrite, copy) NSString *username;
@property (readwrite, copy) NSString *password;
@property (readwrite, copy) NSString *database;
@property (readwrite) NSUInteger port;
@property (readwrite) BOOL useSocket;
@property (readwrite, copy) NSString *socketPath;

@property (readwrite) BOOL useSSL;
@property (readwrite, copy) NSString *sslKeyFilePath;
@property (readwrite, copy) NSString *sslCertificatePath;
@property (readwrite, copy) NSString *sslCACertificatePath;

@property (readwrite, assign) NSUInteger timeout;
@property (readwrite, assign) BOOL retryQueriesOnConnectionFailure;
@property (readwrite, assign) BOOL delegateQueryLogging;

#pragma mark -
#pragma mark Connection and disconnection

- (BOOL)connect;
- (BOOL)reconnect;
- (void)disconnect;

#pragma mark -
#pragma mark Connection state

- (BOOL)isConnected;
- (BOOL)isConnectedViaSSL;
- (BOOL)checkConnection;
- (double)timeConnected;
- (BOOL)userTriggeredDisconnect;

#pragma mark -
#pragma mark Query execution

- (id)streamingQueryString:(NSString *)theQueryString;
- (id)queryString:(NSString *)theQueryString;

#pragma mark -
#pragma mark Database structure

- (NSArray *)databases;
- (NSArray *)tablesFromDatabase:(NSString *)aDatabase;

#pragma mark -
#pragma mark Error information

- (NSUInteger)queryErrorID;
- (NSString *)queryErrorMessage;

@end