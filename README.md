# QtTest
A sample project to demonstrate testing at application without converting it into library
Qt Test is a framework for unit testing Qt based applications and libraries. Most of the example suggests that in order to test QT application,
it must use shared libraries and those libraries are in turn tested by QTest. This is simple example to show how existing application can be
tested as is with only simple changes using QTest::qExec function.  Currently it supports only single window application.
