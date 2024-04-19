// Generated by gencpp from file ublox_msgs/RxmSVSI.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_RXMSVSI_H
#define UBLOX_MSGS_MESSAGE_RXMSVSI_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ublox_msgs/RxmSVSI_SV.h>

namespace ublox_msgs
{
template <class ContainerAllocator>
struct RxmSVSI_
{
  typedef RxmSVSI_<ContainerAllocator> Type;

  RxmSVSI_()
    : iTOW(0)
    , week(0)
    , numVis(0)
    , numSV(0)
    , sv()  {
    }
  RxmSVSI_(const ContainerAllocator& _alloc)
    : iTOW(0)
    , week(0)
    , numVis(0)
    , numSV(0)
    , sv(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _iTOW_type;
  _iTOW_type iTOW;

   typedef int16_t _week_type;
  _week_type week;

   typedef uint8_t _numVis_type;
  _numVis_type numVis;

   typedef uint8_t _numSV_type;
  _numSV_type numSV;

   typedef std::vector< ::ublox_msgs::RxmSVSI_SV_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ublox_msgs::RxmSVSI_SV_<ContainerAllocator> >::other >  _sv_type;
  _sv_type sv;



  enum {
    CLASS_ID = 2u,
    MESSAGE_ID = 32u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::RxmSVSI_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::RxmSVSI_<ContainerAllocator> const> ConstPtr;

}; // struct RxmSVSI_

typedef ::ublox_msgs::RxmSVSI_<std::allocator<void> > RxmSVSI;

typedef boost::shared_ptr< ::ublox_msgs::RxmSVSI > RxmSVSIPtr;
typedef boost::shared_ptr< ::ublox_msgs::RxmSVSI const> RxmSVSIConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::RxmSVSI_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/joe/octagon/src/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmSVSI_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmSVSI_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmSVSI_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
{
  static const char* value()
  {
    return "8358c0613232b962d48cf13f5bda0070";
  }

  static const char* value(const ::ublox_msgs::RxmSVSI_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x8358c0613232b962ULL;
  static const uint64_t static_value2 = 0xd48cf13f5bda0070ULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/RxmSVSI";
  }

  static const char* value(const ::ublox_msgs::RxmSVSI_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# RXM-SVSI (0x02 0x20)\n\
# SV Status Info\n\
#\n\
# Status of the receiver manager knowledge about GPS Orbit Validity\n\
#\n\
# This message has only been retained for backwards compatibility; users are\n\
# recommended to use the UBX-NAV-ORB message in preference.\n\
\n\
uint8 CLASS_ID = 2\n\
uint8 MESSAGE_ID = 32\n\
\n\
int32 iTOW              # GPS time of week of the navigation epoch [ms]\n\
int16 week              # GPS week number of the navigation epoch [weeks]\n\
\n\
uint8 numVis            # Number of visible satellites\n\
uint8 numSV             # Number of per-SV data blocks following\n\
\n\
RxmSVSI_SV[] sv\n\
\n\
================================================================================\n\
MSG: ublox_msgs/RxmSVSI_SV\n\
# see message RxmSVSI\n\
#\n\
\n\
uint8 svid            # Satellite ID\n\
\n\
uint8 svFlag          # Information Flags\n\
uint8 FLAG_URA_MASK = 15      # Figure of Merit (URA) range 0..15\n\
uint8 FLAG_HEALTHY = 16       # SV healthy flag\n\
uint8 FLAG_EPH_VAL = 32       # Ephemeris valid\n\
uint8 FLAG_ALM_VAL = 64       # Almanac valid\n\
uint8 FLAG_NOT_AVAIL = 128    # SV not available\n\
\n\
int16 azim            # Azimuth\n\
int8 elev             # Elevation\n\
\n\
uint8 age             # Age of Almanac and Ephemeris\n\
uint8 AGE_ALM_MASK = 15       # Age of ALM in days offset by 4\n\
                              # i.e. the reference time may be in the future:\n\
                              # ageOfAlm = (age & 0x0f) - 4\n\
uint8 AGE_EPH_MASK = 240      # Age of EPH in hours offset by 4.\n\
                              # i.e. the reference time may be in the future:\n\
                              # ageOfEph = ((age & 0xf0) >> 4) - 4\n\
";
  }

  static const char* value(const ::ublox_msgs::RxmSVSI_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.iTOW);
      stream.next(m.week);
      stream.next(m.numVis);
      stream.next(m.numSV);
      stream.next(m.sv);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RxmSVSI_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::RxmSVSI_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::RxmSVSI_<ContainerAllocator>& v)
  {
    s << indent << "iTOW: ";
    Printer<int32_t>::stream(s, indent + "  ", v.iTOW);
    s << indent << "week: ";
    Printer<int16_t>::stream(s, indent + "  ", v.week);
    s << indent << "numVis: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.numVis);
    s << indent << "numSV: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.numSV);
    s << indent << "sv[]" << std::endl;
    for (size_t i = 0; i < v.sv.size(); ++i)
    {
      s << indent << "  sv[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ublox_msgs::RxmSVSI_SV_<ContainerAllocator> >::stream(s, indent + "    ", v.sv[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_RXMSVSI_H
