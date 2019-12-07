#include "dataFile.hpp"

namespace Core
{

DataFile::DataFile()
    : m_fileStream()
    , m_writeMutex()
{}

DataFile::~DataFile()
{
    m_fileStream.close();
}

void DataFile::open(const std::string& fileName)
{
    m_fileStream.open(fileName);
}

void DataFile::write(short value)
{
    std::lock_guard<std::mutex> lock(m_writeMutex);
    m_fileStream << value << "," << std::flush;
}
    
} // namespace Core
