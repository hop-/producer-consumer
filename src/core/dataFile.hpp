#ifndef CORE_DATAFILE_HPP
#define CORE_DATAFILE_HPP

#include <string>
#include <fstream>
#include <mutex>

namespace Core
{

class DataFile
{
public:
    DataFile();
    ~DataFile();

public:
    void open(const std::string& fileName);
    void write(short value);

private:
    std::ofstream m_fileStream;
    std::mutex m_writeMutex;
};

} // namespace Core

#endif // CORE_DATAFILE_HPP