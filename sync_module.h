#ifndef SYNC_MODULE_H
#define SYNC_MODULE_H

#include <string>
#include <iostream>

class SyncService {
public:
    int syncID;  // ͬ��ID������Ϊ��userID���

    SyncService(int ID) : syncID(ID) {}

    // ͬ�����ݵ��ƶ�
    void syncToCloud() const {
        std::cout << "Syncing data to cloud" << std::endl;
        //todo��������ʵ��Ӧ����ʵ��
    }

    // ���ƶ�ͬ������
    void syncFromCloud() const {
        std::cout << "Syncing data from cloud" << std::endl;
        //todo��������ʵ��Ӧ����ʵ��
    }
};

#endif // SYNC_MODULE_H
