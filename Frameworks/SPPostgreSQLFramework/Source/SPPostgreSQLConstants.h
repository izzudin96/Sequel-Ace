//
//  SPPostgreSQLConstants.h
//  SPPostgreSQLFramework
//
//  Created by Sequel Ace Development Team on December 2024
//  Copyright (c) 2024 Moballo, LLC. All rights reserved.

#import <Foundation/Foundation.h>

// Connection states
typedef NS_ENUM(NSUInteger, SPPostgreSQLConnectionState) {
    SPPostgreSQLDisconnected = 0,
    SPPostgreSQLConnecting   = 1,
    SPPostgreSQLConnected    = 2,
    SPPostgreSQLDisconnecting = 3
};

// Default port for PostgreSQL
#define SP_POSTGRESQL_DEFAULT_PORT 5432

// Common error codes
#define SP_POSTGRESQL_CONNECTION_ERROR   1
#define SP_POSTGRESQL_QUERY_ERROR       2
#define SP_POSTGRESQL_SSL_ERROR         3