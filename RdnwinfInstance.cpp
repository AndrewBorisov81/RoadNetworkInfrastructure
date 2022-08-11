#include "RdnwinfInstance.h"

namespace RNI {

void RdnwinfInstance::init() {
    m_state = State::INIT;
}

void RdnwinfInstance::deinit() {
    m_state = State::DEINIT;
}

void RdnwinfInstance::exec() {
    m_state = State::EXEC;
}

State RdnwinfInstance::getState() const {
    return m_state;
}

} // namespace RNI
