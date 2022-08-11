#pragma once
#include <memory>

namespace RNI {

    enum class State{ INIT, DEINIT, CREATED, EXEC, STOP };

    class RdnwinfInstance {
    public:
        RdnwinfInstance() = default;

        RdnwinfInstance(const RdnwinfInstance&) = default;
        RdnwinfInstance& operator=(const RdnwinfInstance&) = default;
        
        //constexpr RdnwinfInstance(const RdnwinfInstance&&) = default;
        //RdnwinfInstance& operator=(const RdnwinfInstance&&) = default;

        ~RdnwinfInstance() = default;

        void init();
        void deinit();
        void exec();

        State getState() const;

        protected:

        private:
        State m_state{State::CREATED};
    };

} // RNI
