# PostgreSQL Integration for Sequel Ace

This document describes the PostgreSQL integration added to Sequel Ace.

## Overview

PostgreSQL support has been added to Sequel Ace through a new SPPostgreSQLFramework that provides:

- PostgreSQL connection handling
- Basic query execution capabilities
- SSL support
- Connection validation
- Error handling

## Architecture

### New Components

1. **SPPostgreSQLFramework**: A new framework that mirrors the SPMySQLFramework structure
   - `SPPostgreSQLConnection`: Main connection class
   - `SPPostgreSQLConstants`: Constants and connection states
   - `SPPostgreSQLConnectionDelegate`: Delegate protocol for connection events

2. **Database Type Property**: Added `databaseType` property to SPConnectionController
   - 0 = MySQL (default)
   - 1 = PostgreSQL

3. **Connection Logic**: Updated connection initiation to choose between MySQL and PostgreSQL

## Usage

### Programmatic Usage

To create a PostgreSQL connection programmatically:

```objc
// Create connection controller
SPConnectionController *controller = [[SPConnectionController alloc] initWithDocument:document];

// Configure for PostgreSQL
[controller setDatabaseTypeToPostgreSQL:YES];
[controller setHost:@"localhost"];
[controller setUser:@"postgres"];
[controller setPassword:@"password"];
[controller setPort:5432];
[controller setDatabase:@"mydatabase"];

// Initiate connection
[controller initiateConnection:nil];
```

### Direct PostgreSQL Connection

For direct PostgreSQL connection usage:

```objc
SPPostgreSQLConnection *connection = [[SPPostgreSQLConnection alloc] init];
[connection setHost:@"localhost"];
[connection setUsername:@"postgres"];
[connection setPassword:@"password"];
[connection setPort:5432];
[connection setDatabase:@"mydatabase"];

BOOL connected = [connection connect];
if (connected) {
    NSArray *databases = [connection databases];
    // Use connection...
    [connection disconnect];
}
```

## Current Limitations

1. **UI Integration**: The current implementation doesn't include full UI integration. Users need to programmatically set the database type.

2. **libpq Dependency**: The PostgreSQL framework is currently a stub implementation. A real implementation would need to:
   - Link against libpq (PostgreSQL C library)
   - Implement actual connection and query logic
   - Handle PostgreSQL-specific data types and features

3. **Document Integration**: The SPDatabaseDocument class expects MySQL connections. Full PostgreSQL support would require creating a common protocol or updating the document to handle both connection types.

## Future Enhancements

1. **UI Integration**: Add a database type selector to the connection interface
2. **Real libpq Integration**: Implement actual PostgreSQL connectivity
3. **PostgreSQL-specific Features**: Support for PostgreSQL-specific data types, schemas, etc.
4. **Connection Favorites**: Store database type in connection favorites
5. **Migration Tools**: Tools to help migrate between MySQL and PostgreSQL

## Testing

Basic unit tests are included in `SPPostgreSQLConnectionTests.m` that test:
- Connection initialization
- Property setting
- Basic error handling
- Connection validation

## Installation

The PostgreSQL framework is included in the Sequel Ace project and will be built automatically. No additional dependencies are required for the current stub implementation.

For a production implementation, you would need to:
1. Install PostgreSQL development libraries
2. Link against libpq
3. Update the implementation to use actual PostgreSQL API calls