//
//  SPPostgreSQLConnectionTests.m
//  sequel-ace
//
//  Created by Sequel Ace Development Team on December 2024
//  Copyright (c) 2024 Moballo, LLC. All rights reserved.

#import <XCTest/XCTest.h>
#import "SPPostgreSQLConnection.h"

@interface SPPostgreSQLConnectionTests : XCTestCase

@end

@implementation SPPostgreSQLConnectionTests

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testPostgreSQLConnectionInitialization {
    SPPostgreSQLConnection *connection = [[SPPostgreSQLConnection alloc] init];
    
    XCTAssertNotNil(connection, @"PostgreSQL connection should be created successfully");
    XCTAssertFalse([connection isConnected], @"Newly created connection should not be connected");
    XCTAssertEqual([connection port], 5432, @"Default port should be 5432");
    XCTAssertFalse([connection useSSL], @"SSL should be disabled by default");
    XCTAssertEqual([connection timeout], 10, @"Default timeout should be 10 seconds");
}

- (void)testPostgreSQLConnectionBasicProperties {
    SPPostgreSQLConnection *connection = [[SPPostgreSQLConnection alloc] init];
    
    // Test setting properties
    [connection setHost:@"localhost"];
    [connection setUsername:@"testuser"];
    [connection setPassword:@"testpass"];
    [connection setDatabase:@"testdb"];
    [connection setPort:5433];
    [connection setUseSSL:YES];
    
    XCTAssertEqualObjects([connection host], @"localhost", @"Host should be set correctly");
    XCTAssertEqualObjects([connection username], @"testuser", @"Username should be set correctly");
    XCTAssertEqualObjects([connection password], @"testpass", @"Password should be set correctly");
    XCTAssertEqualObjects([connection database], @"testdb", @"Database should be set correctly");
    XCTAssertEqual([connection port], 5433, @"Port should be set correctly");
    XCTAssertTrue([connection useSSL], @"SSL should be enabled");
}

- (void)testPostgreSQLConnectionErrorHandling {
    SPPostgreSQLConnection *connection = [[SPPostgreSQLConnection alloc] init];
    
    // Try to connect without setting host
    BOOL connected = [connection connect];
    
    XCTAssertFalse(connected, @"Connection should fail without host");
    XCTAssertEqual([connection queryErrorID], 1, @"Error ID should be set");
    XCTAssertTrue([[connection queryErrorMessage] length] > 0, @"Error message should be provided");
}

- (void)testPostgreSQLConnectionValidation {
    SPPostgreSQLConnection *connection = [[SPPostgreSQLConnection alloc] init];
    
    // Set host but no username
    [connection setHost:@"localhost"];
    BOOL connected = [connection connect];
    
    XCTAssertFalse(connected, @"Connection should fail without username");
    XCTAssertTrue([[connection queryErrorMessage] containsString:@"Username"], @"Error message should mention username requirement");
}

@end