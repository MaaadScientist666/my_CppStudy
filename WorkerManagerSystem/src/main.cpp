#include <iostream>
#include "../include/WorkerManager.h"
#include "../include/Worker.h"
#include "../include/Boss.h"
#include "../include/Employee.h"
#include "../include/Manager.h"


int main() {
    WorkerManager wm;
    int choice =0;
    while (true) {
        wm.show_menu();
        cout<<"ÇëÊäÈëÄúµÄÑ¡Ôñ£º"<<endl;
        cin>>choice;
        switch (choice) {
            case 0:
                wm.exit_system();
                break;
            case 1:
                wm.add_wk();
                break;
            case 2:
                wm.show_worker();
                break;
            case 3:
                wm.delete_worker();
                break;
            case 4:
                wm.modify_woker();
                break;
            case 5:
                wm.find_woker();
                break;
            case 6:
                wm.sort_worker();
                break;
            case 7:
                wm.delete_all();
                break;
        }
    }


}
