
#pragma once

// std
#include <type_traits>

// local
#include "Image.h"

/// fill an image with a constant value
template < typename T >
Image< T >& fill( Image< T >& im, T value )
{
    Image< T > filled( im.width(), im.height(), value );
    im = std::move( filled );

    return im;
}

template < template<typename> class ImageT, typename ContainedT, typename R >
R pixel_sum_impl( const ImageInterface< ImageT, ContainedT >& im )
{
    R result = 0;
    const ContainedT* p = im.data();
    const ContainedT* e = im.data() + im.pixel_count();
    while ( p < e )
    {
        result += *p++;
    }

    return result;
}

/// find the sum of all pixels
template < template<typename> class ImageT, typename ContainedT >
typename std::enable_if<std::is_integral<ContainedT>::value, int64_t>::type
pixel_sum( const ImageInterface< ImageT, ContainedT >& im )
{
    return pixel_sum_impl<ImageT, ContainedT, int64_t>(im);
}

template < template<typename> class ImageT, typename ContainedT >
typename std::enable_if<!std::is_integral<ContainedT>::value, double>::type
pixel_sum( const ImageInterface< ImageT, ContainedT >& im )
{
    return pixel_sum_impl<ImageT, ContainedT, double>(im);
}
