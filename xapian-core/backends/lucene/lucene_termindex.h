
#ifndef XAPIAN_INCLUDED_LUCENE_TERMINDEX_H
#define XAPIAN_INCLUDED_LUCENE_TERMINDEX_H

#include "bytestream.h"
#include "lucene_fnmtable.h"
#include "lucene_tiitable.h"
#include "lucene_tistable.h"

class LuceneTermIndex {
    /** In memory term indexer
     */
    LuceneTiiTable tii_table;

    /** Maybe need to move it to LuceneSegdb
     */
    LuceneFnmTable fnm_table;

    /** In file term indexer
     */
    LuceneTisTable tis_table;

  public:
    LuceneTermIndex(const string &);

    /** Open .tii/.fnm/.tis tables
     */
    bool create_and_open_tables();
    bool set_filename(string prefix);

    /** Search @target, the result info is stored in @result
     */
    bool seek(const LuceneTerm & target, LuceneTermInfo & result) const;

    /** This is equal to postlist_table.get_termfreq(),
     *  Xapian's termfreq = Lucene's docfreq
     */
    int get_docfreq(const LuceneTerm & lterm) const;

    /** test
     */
    bool test(const string &) const;

    void next_term();

    bool at_end() const;

    /** Get current LuceneTermInfo
     */
    LuceneTermInfo get_current_ti() const;
};

#endif
