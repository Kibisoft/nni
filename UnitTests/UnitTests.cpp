#include "pch.h"
#include "CppUnitTest.h"
#include <chrono>

#include <node.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace nni;

namespace UnitTests
{
	static std::chrono::steady_clock::time_point t0;

	static void begin()
	{
		t0 = std::chrono::steady_clock::now();
	}

	static void end(const std::string& message)
	{
		std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();
		auto duration = t1 - t0;
		Logger::WriteMessage((message + ": " + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(duration).count()) + " ms\n").c_str());
	}

	static std::unique_ptr<leaf> buildTreeUnique(int depth)
	{
		if (depth == 0)
		{
			return std::make_unique<leaf>();
		}
		std::unique_ptr<node> n = std::make_unique<node>();
		for (size_t i = 0; i < 8; ++i)
		{
			n->children.push_back(buildTreeUnique(depth - 1));
		}

		return n;
	}

	TEST_CLASS(UnitTests)
	{
	public:
		
		TEST_METHOD(TestBuild)
		{
			begin();
			std::unique_ptr<leaf> n = buildTreeUnique(8);
			end("build tree unique");

			begin();
			n = nullptr;
			end("delete tree unique");
		}
	};
}
