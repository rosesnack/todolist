#ifndef SYNC_MODULE_H
#define SYNC_MODULE_H

#include <string>
#include <iostream>

class SyncService {
public:
    int syncID;  // 同步ID，可认为与userID相等

    SyncService(int ID) : syncID(ID) {}

    // 同步数据到云端
    void syncToCloud() const {
        std::cout << "Syncing data to cloud" << std::endl;
        //todo：具体在实际应用中实现
    }

    // 从云端同步数据
    void syncFromCloud() const {
        std::cout << "Syncing data from cloud" << std::endl;
        //todo：具体在实际应用中实现
    }
};

#endif // SYNC_MODULE_H
