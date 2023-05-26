/*流控指标：最大打单频率，标识每秒最大允许下单数目，比如整数1000，表示每秒最大下单1000笔，请设计一个高效的流控检查函数*/

#include <iostream>
#include <chrono>
#include <mutex>

class FlowController {
public:
    // 检查是否允许下单
    bool CheckOrderAllowed() {
        std::lock_guard<std::mutex> lock(mutex);

        // 获取当前时间
        auto currentTime = std::chrono::steady_clock::now();

        // 计算时间间隔，单位为秒
        auto timeInterval = std::chrono::duration_cast<std::chrono::seconds>(currentTime - lastUpdateTime).count();

        if (timeInterval >= 1) {
            // 如果时间间隔大于等于1秒，重置计数器和时间
            counter = 0;
            lastUpdateTime = currentTime;
        }

        // 检查计数器是否超过最大下单数
        if (counter < maxOrderPerSecond) {
            counter++;
            return true;
        }

        return false;
    }

private:
    int maxOrderPerSecond;  // 最大下单数
    int counter;  // 当前计数器
    std::chrono::steady_clock::time_point lastUpdateTime;  // 上次更新时间
    std::mutex mutex;  // 互斥锁，用于保护共享数据
};

int main() {
    FlowController flowController(1000);

    // 模拟多个线程并发下单
    for (int i = 0; i < 10; ++i) {
        std::thread t([&]() {
            for (int j = 0; j < 1000; ++j) {
                if (flowController.CheckOrderAllowed()) {
                    std::cout << "Order placed successfully." << std::endl;
                } else {
                    std::cout << "Order rejected due to flow control." << std::endl;
                }
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });

        t.detach();
    }

    // 等待一段时间，观察流控效果
    std::this_thread::sleep_for(std::chrono::seconds(10));

    return 0;
}