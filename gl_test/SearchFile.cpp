#include "SearchFile.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <thread>
#include <vector>

namespace fs = std::filesystem;

namespace FileManager
{
	SearchFile::SearchFile()
	{	
		maxThreads = 8;
		count = 0;
		isFound = false;

		setRootDir("C:\\");
	}

	void SearchFile::setFileName(std::string fName)
	{
		fileName = fName;
	}

	void SearchFile::setRootDir(std::string rDir)
	{	
		rootDir = fs::path(rDir);
	}

	void SearchFile::runSearching(std::string fName)
	{	
		setFileName(fName);
		startNewDirSearch(rootDir);
	}

	void SearchFile::createNewThread(fs::path path)
	{	
		count++;
		startNewDirSearch(path);
		count--;
	}

	void SearchFile::startNewDirSearch(fs::path path)
	{
		try {

			if (isFound) return;

			for (const auto& dirEntry : std::filesystem::recursive_directory_iterator(path, fs::directory_options::skip_permission_denied))
			{
				std::string sPath = dirEntry.path().string();

				if (dirEntry.is_directory())
				{
					
					if (isFound) return;

					if (count <= maxThreads)
					{
						std::thread th = std::thread(&SearchFile::createNewThread, this, dirEntry);
						th.detach();
					}
				}

				std::string base_filename = sPath.substr(sPath.find_last_of("/\\") + 1);
				std::string::size_type const p(base_filename.find_last_of('.'));
				std::string file_without_extension = base_filename.substr(0, p);
			
				if (file_without_extension == fileName && !isFound)
				{	
					isFound = true;
					std::cout << "Your file is found: " << sPath << std::endl;
					return;
				}
			}
		}
		catch (std::filesystem::filesystem_error const& ex)
		{
			std::cout << ex.what() << std::endl;
			return;
		}
		catch (...)
		{	
			return;
		}
			
	}
}
