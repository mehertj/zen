/*
 Copyright (c) 2013 MeherTJ G.
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of
 this software and associated documentation files (the "Software"), to deal in
 the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

#include <ctime>
#include <chrono>

namespace Zen
{
	typedef std::chrono::microseconds Microseconds;

	template<typename TTimeDuration>
	double ToSeconds(TTimeDuration mic)
	{
		return (double)mic.count() / (double)TTimeDuration::period::den;
	}

	inline Microseconds ToMicroseconds(double seconds)
	{
		std::chrono::microseconds mc((long long)(seconds * std::chrono::microseconds::period::den));
		return mc;
	}

	inline static std::chrono::microseconds Now()
	{
		//std::micro
		using namespace std::chrono;
		return duration_cast<microseconds>(system_clock::now().time_since_epoch());
	}
	class Ticker {
	public:
		inline Ticker()
		{
			mStartTime = Now();
		}
		std::chrono::microseconds duration()
		{
			return Now() - mStartTime;
		}
		std::chrono::microseconds tick()
		{
			auto now = Now();
			auto interval = now - mStartTime;
			mStartTime = now;
			return interval;
		}
		std::chrono::microseconds tick(std::chrono::microseconds move)
		{
			auto now = Now();
			auto interval = now - mStartTime;
			mStartTime = now - move;
			return interval;
		}
	protected:
		std::chrono::microseconds mStartTime;
	};
}