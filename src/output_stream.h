#ifndef OUTPUT_STREAM_H
#define OUTPUT_STREAM_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

class OutputStream
{
public:
    virtual ~OutputStream() { }
    virtual OutputStream &operator<<(const std::string &str) = 0;
};

class FileOutputStream : public OutputStream
{
    std::ofstream outfile;

public:
    FileOutputStream(const std::string &filename) : outfile(filename)
    {
        if (!outfile)
        {
            throw std::runtime_error("Error opening file for writing");
        }
    }

    ~FileOutputStream()
    {
        outfile.close();
    }

    OutputStream &operator<<(const std::string &str)
    {
        outfile << str;
        return *this;
    }
};

class MemoryOutputStream : public OutputStream
{
    std::ostringstream oss;

public:
    OutputStream &operator<<(const std::string &str)
    {
        oss << str;
        return *this;
    }

    std::string str() const
    {
        return oss.str();
    }
};

#endif
