// Generated by gencpp from file ublox_msgs/MonGNSS.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_MONGNSS_H
#define UBLOX_MSGS_MESSAGE_MONGNSS_H


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
struct MonGNSS_
{
  typedef MonGNSS_<ContainerAllocator> Type;

  MonGNSS_()
    : version(0)
    , supported(0)
    , defaultGnss(0)
    , enabled(0)
    , simultaneous(0)
    , reserved1()  {
      reserved1.assign(0);
  }
  MonGNSS_(const ContainerAllocator& _alloc)
    : version(0)
    , supported(0)
    , defaultGnss(0)
    , enabled(0)
    , simultaneous(0)
    , reserved1()  {
  (void)_alloc;
      reserved1.assign(0);
  }



   typedef uint8_t _version_type;
  _version_type version;

   typedef uint8_t _supported_type;
  _supported_type supported;

   typedef uint8_t _defaultGnss_type;
  _defaultGnss_type defaultGnss;

   typedef uint8_t _enabled_type;
  _enabled_type enabled;

   typedef uint8_t _simultaneous_type;
  _simultaneous_type simultaneous;

   typedef boost::array<uint8_t, 3>  _reserved1_type;
  _reserved1_type reserved1;



  enum {
    CLASS_ID = 10u,
    MESSAGE_ID = 40u,
    BIT_MASK_GPS = 1u,
    BIT_MASK_GLONASS = 2u,
    BIT_MASK_BEIDOU = 4u,
    BIT_MASK_GALILEO = 8u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::MonGNSS_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::MonGNSS_<ContainerAllocator> const> ConstPtr;

}; // struct MonGNSS_

typedef ::ublox_msgs::MonGNSS_<std::allocator<void> > MonGNSS;

typedef boost::shared_ptr< ::ublox_msgs::MonGNSS > MonGNSSPtr;
typedef boost::shared_ptr< ::ublox_msgs::MonGNSS const> MonGNSSConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::MonGNSS_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::MonGNSS_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::MonGNSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::MonGNSS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::MonGNSS_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "0986728889e4abf5eac46b70b74047ed";
  }

  static const char* value(const ::ublox_msgs::MonGNSS_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x0986728889e4abf5ULL;
  static const uint64_t static_value2 = 0xeac46b70b74047edULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/MonGNSS";
  }

  static const char* value(const ::ublox_msgs::MonGNSS_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# MON-GNSS (0x0A 0x28)\n\
# Information message major GNSS selection\n\
#\n\
# This message reports major GNSS selection. Augmentation systems are not\n\
# reported.\n\
# \n\
\n\
uint8 CLASS_ID = 10\n\
uint8 MESSAGE_ID = 40\n\
\n\
uint8 version         # Message version (0x01 for this version)\n\
\n\
uint8 BIT_MASK_GPS = 1\n\
uint8 BIT_MASK_GLONASS = 2\n\
uint8 BIT_MASK_BEIDOU = 4\n\
uint8 BIT_MASK_GALILEO = 8\n\
\n\
uint8 supported       # The major GNSS that can be supported by this receiver\n\
uint8 defaultGnss     # Default major GNSS selection. If the default major GNSS \n\
                      # selection is currently configured in the efuse for this \n\
                      # receiver, it takes precedence over the default major \n\
                      # GNSS selection configured in the executing firmware of \n\
                      # this receiver.\n\
                      # see bit mask constants\n\
uint8 enabled         # Current major GNSS selection enabled for this receiver\n\
                      # see bit mask constants\n\
\n\
uint8 simultaneous    # Maximum number of concurrent major GNSS that can be \n\
                      # supported by this receiver\n\
\n\
uint8[3] reserved1    # Reserved\n\
";
  }

  static const char* value(const ::ublox_msgs::MonGNSS_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.version);
      stream.next(m.supported);
      stream.next(m.defaultGnss);
      stream.next(m.enabled);
      stream.next(m.simultaneous);
      stream.next(m.reserved1);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct MonGNSS_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::MonGNSS_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::MonGNSS_<ContainerAllocator>& v)
  {
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "supported: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.supported);
    s << indent << "defaultGnss: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.defaultGnss);
    s << indent << "enabled: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.enabled);
    s << indent << "simultaneous: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.simultaneous);
    s << indent << "reserved1[]" << std::endl;
    for (size_t i = 0; i < v.reserved1.size(); ++i)
    {
      s << indent << "  reserved1[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved1[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_MONGNSS_H
