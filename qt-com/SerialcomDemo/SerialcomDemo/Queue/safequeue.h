#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H
#include <mutex>
#include <condition_variable>
#include <deque>
#include <tuple>

// stl库中的队列容器并不支持线程安全
// 自定义线程安全队列

template<typename T>
class SafeQueue
{
public:
    SafeQueue(){}
    ~SafeQueue(){}

public:
    // 将数据推入队列
    inline void push_back(const T& task)
    {
        {
            std::lock_guard<std::mutex> locker(m_mutex);
            m_tasks.push_back(task);
        }
        m_cv.notify_one();
    }

    // 取数据的方式可分为两种
    // 阻塞模式
    inline T take_front_block()
    {
        std::unique_lock<std::mutex> locker(m_mutex);
        while(m_tasks.empty())
        {
            // 队列为空时，挂起该线程
            m_cv.wait(locker);
        }
        // 获取数据的同时，从该队列移除该数据
        T task = m_tasks.front();
        m_tasks.pop_front();
        return task;
    }

    // 非阻塞模式
    inline std::tuple<bool, T> take_front_unblock()
    {
        std::lock_guard<std::mutex> locker(m_mutex);
        std::tuple<bool, T> data;
        if(!m_tasks.empty())
        {
            data = std::make_tuple<bool, T&>(true, m_tasks.front());
            m_tasks.pop_front();
        }
        else
        {
            T task;
            data = std::make_tuple<bool, T&>(false, task);
        }
        return data;
    }

private:
    std::deque<T>   m_tasks;
    std::mutex      m_mutex;
    std::condition_variable m_cv;
};

#endif // SAFEQUEUE_H
