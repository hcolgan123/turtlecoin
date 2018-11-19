/***
* This file is based on or incorporates material from the UnitTest++ r30 open source project.
* Microsoft is not the original author of this code but has modified it and is licensing the code under 
* the MIT License. Microsoft reserves all other rights not expressly granted under the MIT License, 
* whether by implication, estoppel or otherwise. 
*
* UnitTest++ r30 
*
* Copyright (c) 2006 Noel Llopis and Charles Nicholson
* Portions Copyright (c) Microsoft Corporation
*
* All Rights Reserved.
*
* MIT License
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software 
* and associated documentation files (the "Software"), to deal in the Software without restriction, 
* including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
* and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, 
* subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or 
* substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, 
* INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE 
* AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
***/

#include "stdafx.h"

#ifndef UNITTEST_NO_DEFERRED_REPORTER

#include "DeferredTestResult.h"

namespace UnitTest
{

DeferredTestFailure::DeferredTestFailure()
	: lineNumber(-1)
{
	failureStr[0] = '\0';
}

DeferredTestFailure::DeferredTestFailure(int lineNumber_, const char* failureStr_)
	: lineNumber(lineNumber_)
{
// Ignoring warning about possible overrun because we aren't going to entirely
// change how unittestpp deals with strings.
#if defined(_MSC_VER)
#pragma warning (push)
#pragma warning (disable : 6204)
#endif
	std::strcpy(failureStr, failureStr_);
#if defined(_MSC_VER)
#pragma warning (pop)
#endif
}

DeferredTestResult::DeferredTestResult()
	: suiteName("")
	, testName("")
	, failureFile("")
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredTestResult::DeferredTestResult(char const* suite, char const* test)
	: suiteName(suite)
	, testName(test)
	, failureFile("")
	, timeElapsed(0.0f)
	, failed(false)
{
}

DeferredTestResult::~DeferredTestResult()
{
}

}

#endif
