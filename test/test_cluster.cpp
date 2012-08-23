#include <string>
#include <vector>

#include <cppunit/Portability.h>
#include <cppunit/portability/CppUnitSet.h>
#include <cppunit/extensions/TestFactory.h>
#include <cppunit/TestCase.h>

#include <disambiguation.h>
#include <engine.h>
#include <cluster.h>

#include "testdata.h"

class ClusterTest : public CppUnit::TestCase {

public:
  ClusterTest(std::string name) : CppUnit::TestCase(name) {}

  void create_cluster() {
    Record * r = make_quuxalot_record();
    ClusterHead ch(r, 0.9953);
    RecordList rl = get_record_list();
    Cluster * c = new Cluster(ch, rl);
    delete c;
  }

  void runTest() {
    create_cluster();
  }
};


void
test_clusters() {

  ClusterTest * rt = new ClusterTest(std::string("initial test"));
  rt->runTest();
  delete rt;
}


#ifdef test_cluster_STANDALONE
int
main(int UP(argc), char ** UP(argv)) {

  test_clusters();
  return 0;
}
#endif
