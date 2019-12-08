#ifndef CORE_DATAFILE_HPP
#define CORE_DATAFILE_HPP

#include <string>
#include <fstream>
#include <mutex>

namespace Core
{

// class DataFile to manage synchronized write into file
class DataFile
{
public:
    DataFile();
    ~DataFile();

public:
    // open file to work with
    void open(const std::string& fileName);
    // synchronized write function
    void write(short value);

private:
    // file stream
    std::ofstream m_fileStream;
    // mutex for file to be synchronized
    std::mutex m_writeMutex;
};

} // namespace Core

#endif // CORE_DATAFILE_HPP