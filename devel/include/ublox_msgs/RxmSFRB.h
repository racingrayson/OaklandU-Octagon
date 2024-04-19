// Generated by gencpp from file ublox_msgs/RxmSFRB.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_RXMSFRB_H
#define UBLOX_MSGS_MESSAGE_RXMSFRB_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ublox_msgs
{
template <class ContainerAllocator>
struct RxmSFRB_
{
  typedef RxmSFRB_<ContainerAllocator> Type;

  RxmSFRB_()
    : chn(0)
    , svid(0)
    , dwrd()  {
      dwrd.assign(0);
  }
  RxmSFRB_(const ContainerAllocator& _alloc)
    : chn(0)
    , svid(0)
    , dwrd()  {
  (void)_alloc;
      dwrd.assign(0);
  }



   typedef uint8_t _chn_type;
  _chn_type chn;

   typedef uint8_t _svid_type;
  _svid_type svid;

   typedef boost::array<uint32_t, 10>  _dwrd_type;
  _dwrd_type dwrd;



  enum {
    CLASS_ID = 2u,
    MESSAGE_ID = 17u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::RxmSFRB_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::RxmSFRB_<ContainerAllocator> const> ConstPtr;

}; // struct RxmSFRB_

typedef ::ublox_msgs::RxmSFRB_<std::allocator<void> > RxmSFRB;

typedef boost::shared_ptr< ::ublox_msgs::RxmSFRB > RxmSFRBPtr;
typedef boost::shared_ptr< ::ublox_msgs::RxmSFRB const> RxmSFRBConstPtr;

// constants requiring out of line definition

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::RxmSFRB_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace ublox_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'ublox_msgs': ['/home/joe/octagon/src/ublox/ublox_msgs/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::RxmSFRB_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::RxmSFRB_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::RxmSFRB_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eec72635c768d0528138f40de7442203";
  }

  static const char* value(const ::ublox_msgs::RxmSFRB_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeec72635c768d052ULL;
  static const uint64_t static_value2 = 0x8138f40de7442203ULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/RxmSFRB";
  }

  static const char* value(const ::ublox_msgs::RxmSFRB_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# RXM-SFRB (0x02 0x11)\n\
# Subframe Buffer\n\
#\n\
# The content of one single subframe buffer\n\
# For GPS satellites, the 10 dwrd values contain the parity checked subframe \n\
# data for 10 Words. Each dwrd has 24 Bits with valid data (Bits 23 to 0). The \n\
# remaining 8 bits (31 to 24) have an undefined value. The direction within the \n\
# Word is that the higher order bits are received from the SV first. Example: \n\
# The Preamble can be found in dwrd[0], at bit position 23 down to 16. For more \n\
# details on the data format please refer to the ICD-GPS-200C\n\
# Interface document.\n\
# For SBAS satellites, the 250 Bit message block can be found in dwrd[0] to \n\
# dwrd[6] for the first 224 bits. The remaining 26 bits are in dwrd[7], whereas\n\
# Bits 25 and 24 are the last two data bits, and Bits 23 down to 0 are the\n\
# parity bits. For more information on SBAS data format, please refer to \n\
# RTCA/DO-229C (MOPS), Appendix A.\n\
#\n\
\n\
uint8 CLASS_ID = 2\n\
uint8 MESSAGE_ID = 17\n\
\n\
uint8 chn               # Channel Number\n\
uint8 svid              # ID of Satellite transmitting Subframe\n\
uint32[10] dwrd         # Words of Data\n\
";
  }

  static const char* value(const ::ublox_msgs::RxmSFRB_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.chn);
      stream.next(m.svid);
      stream.next(m.dwrd);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RxmSFRB_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::RxmSFRB_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::RxmSFRB_<ContainerAllocator>& v)
  {
    s << indent << "chn: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.chn);
    s << indent << "svid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.svid);
    s << indent << "dwrd[]" << std::endl;
    for (size_t i = 0; i < v.dwrd.size(); ++i)
    {
      s << indent << "  dwrd[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.dwrd[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_RXMSFRB_H
