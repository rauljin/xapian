
#include <config.h>

#include "lucene_segmentgentable.h"

#include "debuglog.h"

//test
#include <iostream>

LuceneSegmentGenTable::LuceneSegmentGenTable(const string & db_dir_)
        : db_dir(db_dir_),
          file_name("segments.gen"),
          stream_reader(db_dir, file_name)
{
    LOGCALL_CTOR(DB, "LuceneSegmentGenTable", db_dir);
}

bool 
LuceneSegmentGenTable::open()
{
    stream_reader.open_stream();

    stream_reader.read_int32(version);
    stream_reader.read_int64(generationA);
    stream_reader.read_int64(generationB);

    return true;
}

int
LuceneSegmentGenTable::get_version()
{
    return version;
}

long long
LuceneSegmentGenTable::get_generationA()
{
    return generationA;
}

long long
LuceneSegmentGenTable::get_generationB()
{
    return generationB;
}

//Just for debug
void LuceneSegmentGenTable::debug_get_table()
{
    cout << "LuceneSegmentGenTable::debgu_get_table" << endl;
    cout << "segments.gen-->version(" << version << "), generationA(" 
        << generationA << "),generationB(" << generationB << ")";
    cout << endl;
}
