#pragma once

namespace rdr
{
    //class CubeMap;
    //class ShaderProgram;

    //using DrawOrderType = int;

    //namespace draw_order
    //{
    //    // First in queue
    //    constexpr static DrawOrderType First = std::numeric_limits<DrawOrderType>::min();

    //    // Last in queue
    //    constexpr static DrawOrderType Last = std::numeric_limits<DrawOrderType>::max();
    //}

    struct DrawCall
    {
        glm::vec3 position;
    };

    //bool operator <(const DrawCall& first, const DrawCall& second)
    //{
    //    return first.drawOrder < second.drawOrder;
    //}
}