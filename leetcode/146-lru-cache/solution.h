#include "header.h"

struct CacheNode {
  int key;
  int value;
};

std::ostream& operator<<(std::ostream& ostr, const std::list<CacheNode>& list) {
  for (auto& i : list) {
    ostr << ' ' << i.key;
  };
  return ostr;
}

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) {}

  int get(int key) {
    if (!nodeMap_.contains(key)) {
      return -1;
    }
    auto it = nodeMap_.at(key);
    nodeList_.splice(nodeList_.begin(), nodeList_, it);
    return it->value;
  }

  void put(int key, int value) {
    if (nodeMap_.contains(key)) {
      auto it = nodeMap_.at(key);
      it->value = value;
      nodeList_.splice(nodeList_.begin(), nodeList_, it);
      return;
    }

    if (nodeMap_.size() >= capacity_) {
      nodeMap_.erase(nodeList_.back().key);
      nodeList_.pop_back();
    }
    CacheNode node{.key = key, .value = value};
    nodeList_.push_front(node);
    nodeMap_[key] = nodeList_.begin();
  }

 private:
  int capacity_;
  std::list<CacheNode> nodeList_;
  std::unordered_map<int, std::list<CacheNode>::iterator> nodeMap_;
};