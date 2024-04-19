// Generated by gencpp from file ublox_msgs/EsfSTATUS.msg
// DO NOT EDIT!


#ifndef UBLOX_MSGS_MESSAGE_ESFSTATUS_H
#define UBLOX_MSGS_MESSAGE_ESFSTATUS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ublox_msgs/EsfSTATUS_Sens.h>

namespace ublox_msgs
{
template <class ContainerAllocator>
struct EsfSTATUS_
{
  typedef EsfSTATUS_<ContainerAllocator> Type;

  EsfSTATUS_()
    : iTOW(0)
    , version(0)
    , reserved1()
    , fusionMode(0)
    , reserved2()
    , numSens(0)
    , sens()  {
      reserved1.assign(0);

      reserved2.assign(0);
  }
  EsfSTATUS_(const ContainerAllocator& _alloc)
    : iTOW(0)
    , version(0)
    , reserved1()
    , fusionMode(0)
    , reserved2()
    , numSens(0)
    , sens(_alloc)  {
  (void)_alloc;
      reserved1.assign(0);

      reserved2.assign(0);
  }



   typedef uint32_t _iTOW_type;
  _iTOW_type iTOW;

   typedef uint8_t _version_type;
  _version_type version;

   typedef boost::array<uint8_t, 7>  _reserved1_type;
  _reserved1_type reserved1;

   typedef uint8_t _fusionMode_type;
  _fusionMode_type fusionMode;

   typedef boost::array<uint8_t, 2>  _reserved2_type;
  _reserved2_type reserved2;

   typedef uint8_t _numSens_type;
  _numSens_type numSens;

   typedef std::vector< ::ublox_msgs::EsfSTATUS_Sens_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::ublox_msgs::EsfSTATUS_Sens_<ContainerAllocator> >::other >  _sens_type;
  _sens_type sens;



  enum {
    CLASS_ID = 16u,
    MESSAGE_ID = 16u,
    FUSION_MODE_INIT = 0u,
    FUSION_MODE_FUSION = 1u,
    FUSION_MODE_SUSPENDED = 2u,
    FUSION_MODE_DISABLED = 3u,
  };


  typedef boost::shared_ptr< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> const> ConstPtr;

}; // struct EsfSTATUS_

typedef ::ublox_msgs::EsfSTATUS_<std::allocator<void> > EsfSTATUS;

typedef boost::shared_ptr< ::ublox_msgs::EsfSTATUS > EsfSTATUSPtr;
typedef boost::shared_ptr< ::ublox_msgs::EsfSTATUS const> EsfSTATUSConstPtr;

// constants requiring out of line definition

   

   

   

   

   

   



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ublox_msgs::EsfSTATUS_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "006f2c0e3e6e9239781223dca67e519b";
  }

  static const char* value(const ::ublox_msgs::EsfSTATUS_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x006f2c0e3e6e9239ULL;
  static const uint64_t static_value2 = 0x781223dca67e519bULL;
};

template<class ContainerAllocator>
struct DataType< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ublox_msgs/EsfSTATUS";
  }

  static const char* value(const ::ublox_msgs::EsfSTATUS_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ESF-STATUS (0x10 0x10)\n\
# External Sensor Fusion (ESF) status information\n\
#\n\
# Supported on UDR/ADR products\n\
#\n\
\n\
uint8 CLASS_ID = 16\n\
uint8 MESSAGE_ID = 16\n\
\n\
uint32 iTOW                   # GPS time of week of the navigation epoch [ms]\n\
uint8 version                 # Message version (2 for this version)\n\
\n\
uint8[7] reserved1            # Reserved\n\
\n\
uint8 fusionMode              # Fusion mode:\n\
uint8 FUSION_MODE_INIT = 0        # receiver is initializing some unknown values\n\
                                  # required for doing sensor fusion\n\
uint8 FUSION_MODE_FUSION = 1      # GNSS and sensor data are \n\
                                  # used for navigation solution computation\n\
uint8 FUSION_MODE_SUSPENDED = 2   # sensor fusion is temporarily disabled \n\
                                  # due to e.g. invalid sensor data or detected \n\
                                  # ferry\n\
uint8 FUSION_MODE_DISABLED = 3    # sensor fusion is permanently disabled \n\
                                  # until receiver reset due e.g. to sensor \n\
                                  # error\n\
\n\
uint8[2] reserved2            # Reserved\n\
\n\
uint8 numSens                 # Number of sensors\n\
\n\
\n\
# Start of repeated block (numSens times)\n\
EsfSTATUS_Sens[] sens\n\
# End of repeated block\n\
================================================================================\n\
MSG: ublox_msgs/EsfSTATUS_Sens\n\
# See Esf-STATUS\n\
#\n\
\n\
uint8 sensStatus1   # Sensor status, part 1 (see graphic below)\n\
uint8 sensStatus2   # Sensor status, part 2 (see graphic below)\n\
uint8 freq          # Observation frequency [Hz]\n\
uint8 faults        # Sensor faults (see graphic below)\n\
";
  }

  static const char* value(const ::ublox_msgs::EsfSTATUS_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.iTOW);
      stream.next(m.version);
      stream.next(m.reserved1);
      stream.next(m.fusionMode);
      stream.next(m.reserved2);
      stream.next(m.numSens);
      stream.next(m.sens);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct EsfSTATUS_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ublox_msgs::EsfSTATUS_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ublox_msgs::EsfSTATUS_<ContainerAllocator>& v)
  {
    s << indent << "iTOW: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.iTOW);
    s << indent << "version: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.version);
    s << indent << "reserved1[]" << std::endl;
    for (size_t i = 0; i < v.reserved1.size(); ++i)
    {
      s << indent << "  reserved1[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved1[i]);
    }
    s << indent << "fusionMode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.fusionMode);
    s << indent << "reserved2[]" << std::endl;
    for (size_t i = 0; i < v.reserved2.size(); ++i)
    {
      s << indent << "  reserved2[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.reserved2[i]);
    }
    s << indent << "numSens: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.numSens);
    s << indent << "sens[]" << std::endl;
    for (size_t i = 0; i < v.sens.size(); ++i)
    {
      s << indent << "  sens[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ublox_msgs::EsfSTATUS_Sens_<ContainerAllocator> >::stream(s, indent + "    ", v.sens[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // UBLOX_MSGS_MESSAGE_ESFSTATUS_H
