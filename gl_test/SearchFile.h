#pragma once

#include <vector>
#include <thread>
#include <atomic>
#include <string>
#include <filesystem>
namespace fs = std::filesystem;

namespace FileManager
{
	class SearchFile
	{
		std::string fileName;
		fs::path rootDir;
		std::string itemFound;
		int maxThreads;
		int count;
		std::atomic<bool> isFound;
		std::vector<std::thread> threads;
	public:
		SearchFile();
		void setFileName(std::string fileName);
		void setRootDir(std::string rDir);
		void runSearching(std::string fName);
		void createNewThread(fs::path path);
		void startNewDirSearch(fs::path path);
	};
}
