#include <chrono>
#include <string>
#include <iostream>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <thread>
#include <vector>
#include <fstream>
#include <algorithm>
#include <tf2/LinearMath/Quaternion.h>

#include "geometry_msgs/msg/transform_stamped.hpp"


#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/bool.hpp"
#include <std_msgs/msg/u_int16.hpp>
#include "rosgraph_msgs/msg/clock.hpp"
#include "nav_msgs/msg/odometry.hpp"

#include "autonoma_msgs/msg/ground_truth_array.hpp"
#include "autonoma_msgs/msg/powertrain_data.hpp"
#include "autonoma_msgs/msg/race_control.hpp"
#include "autonoma_msgs/msg/to_raptor.hpp"
#include "autonoma_msgs/msg/vehicle_data.hpp"
#include "autonoma_msgs/msg/vehicle_inputs.hpp"

#include "vectornav_msgs/msg/common_group.hpp"
#include "vectornav_msgs/msg/attitude_group.hpp"
#include "vectornav_msgs/msg/gps_group.hpp"
#include "vectornav_msgs/msg/imu_group.hpp"
#include "vectornav_msgs/msg/ins_group.hpp"
#include "vectornav_msgs/msg/time_group.hpp"

#include "novatel_oem7_msgs/msg/bestpos.hpp"
#include "novatel_oem7_msgs/msg/bestvel.hpp"
#include "novatel_oem7_msgs/msg/inspva.hpp"
#include "novatel_oem7_msgs/msg/heading2.hpp"
// #include "novatel_oem7_msgs/msg/rawimu.hpp"

#include "foxglove_msgs/msg/scene_update.hpp"

#include <can_msgs/msg/frame.hpp>

#include "iac_qos.h"

#include "VESIAPI.h"
#include "VESIResultData.h"

#include "ASMBus_renamed.h"
#include "RaceControlInterface.h"
#include "sut-te-bridge/canid_enum.hpp"

#include <can_dbc_parser/Dbc.hpp>
#include <can_dbc_parser/DbcBuilder.hpp>
#include <can_dbc_parser/DbcMessage.hpp>
#include <can_dbc_parser/DbcSignal.hpp>

#include <GeographicLib/LocalCartesian.hpp>
#include <GeographicLib/Geocentric.hpp>
#include <GeographicLib/UTMUPS.hpp>

namespace bridge
{
    class SutTeBridgeNode : public rclcpp::Node
    {

    public:
        SutTeBridgeNode();
        ~SutTeBridgeNode() = default;

    private:
        // Publisher
        rclcpp::Publisher<autonoma_msgs::msg::RaceControl>::SharedPtr raceControlDataPublisher_;
        rclcpp::Publisher<autonoma_msgs::msg::VehicleData>::SharedPtr vehicleDataPublisher_;
        rclcpp::Publisher<autonoma_msgs::msg::PowertrainData>::SharedPtr powertrainDataPublisher_;
        rclcpp::Publisher<autonoma_msgs::msg::GroundTruthArray>::SharedPtr groundTruthArrayPublisher_;

        rclcpp::Publisher<vectornav_msgs::msg::CommonGroup>::SharedPtr verctorNavCommonGroupPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::AttitudeGroup>::SharedPtr verctorNavAttitudeGroupPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::ImuGroup>::SharedPtr verctorNavImuGroupPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::InsGroup>::SharedPtr verctorNavInsGroupPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::GpsGroup>::SharedPtr verctorNavGpsGroupLeftPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::GpsGroup>::SharedPtr verctorNavGpsGroupRightPublisher_;
        rclcpp::Publisher<vectornav_msgs::msg::TimeGroup>::SharedPtr verctorNavTimeGroupPublisher_;

        rclcpp::Publisher<vectornav_msgs::msg::GpsGroup>::SharedPtr verctorNavGpsGroupPublisher;

        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestPosPublisher;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestGNSSPosPublisher;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestVelPublisher;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestGNSSVelPublisher;
        rclcpp::Publisher<novatel_oem7_msgs::msg::INSPVA>::SharedPtr novaTelInspvaPublisher;
        rclcpp::Publisher<novatel_oem7_msgs::msg::HEADING2>::SharedPtr novaTelHeading2Publisher;
        // rclcpp::Publisher<novatel_oem7_msgs::msg::RAWIMU>::SharedPtr novaTelRawImuPublisher;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelRawImuXPublisher;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelImuPublisher;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr novaTelOdomPublisher;
        rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr novaTelFixPublisher;

        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestPosPublisher1_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestGNSSPosPublisher1_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestVelPublisher1_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestGNSSVelPublisher1_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::INSPVA>::SharedPtr novaTelInspvaPublisher1_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::HEADING2>::SharedPtr novaTelHeading2Publisher1_;
        // rclcpp::Publisher<novatel_oem7_msgs::msg::RAWIMU>::SharedPtr novaTelRawImuPublisher1_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelRawImuXPublisher1_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelImuPublisher1_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr novaTelOdomPublisher1_;
        rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr novaTelFixPublisher1_;

        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestPosPublisher2_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTPOS>::SharedPtr novaTelBestGNSSPosPublisher2_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestVelPublisher2_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::BESTVEL>::SharedPtr novaTelBestGNSSVelPublisher2_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::INSPVA>::SharedPtr novaTelInspvaPublisher2_;
        rclcpp::Publisher<novatel_oem7_msgs::msg::HEADING2>::SharedPtr novaTelHeading2Publisher2_;
        // rclcpp::Publisher<novatel_oem7_msgs::msg::RAWIMU>::SharedPtr novaTelRawImuPublisher2_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelRawImuXPublisher2_;
        rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr novaTelImuPublisher2_;
        rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr novaTelOdomPublisher2_;
        rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr novaTelFixPublisher2_;

        rclcpp::Publisher<sensor_msgs::msg::NavSatFix>::SharedPtr foxgloveMapPublisher_;
        rclcpp::Publisher<foxglove_msgs::msg::SceneUpdate>::SharedPtr foxgloveScenePublisher_;
        rclcpp::Publisher<geometry_msgs::msg::TransformStamped>::SharedPtr egoPositionPublisher_;

        rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr resetCommandPublisher_;

        rclcpp::Publisher<Frame>::SharedPtr canPublisher_;
        rclcpp::Subscription<can_msgs::msg::Frame>::SharedPtr canSubscriber_;

        // Timer
        rclcpp::TimerBase::SharedPtr updateVESIVehicleInputs_;

        // Subsciber
        rclcpp::Subscription<autonoma_msgs::msg::VehicleInputs>::SharedPtr receiveVehicleCommands_;
        rclcpp::Subscription<autonoma_msgs::msg::ToRaptor>::SharedPtr receiveRaptorCommands_;
        rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr useCustomRaceControlSource_;
        rclcpp::Subscription<std_msgs::msg::UInt16>::SharedPtr simTimeIncrease_;
        rclcpp::Publisher<rosgraph_msgs::msg::Clock>::SharedPtr simClockTimePublisher_;


        //Constants for orientation calculation
        double wgs84_a = 6378137.0;
        double wgs84_f = 1.0 / 298.257223563;
        double prev_x_ = 0.0;
        double prev_y_ = 0.0;
        // This origin is for IMS
        double lat0 = 39.7947350319205384;
        double lon0 = -86.2352425671970906;
        double hgt0 = 224.1435846661534015;
        // GPS Map
        GeographicLib::LocalCartesian gps_map_ = GeographicLib::LocalCartesian(lat0, lon0, hgt0, GeographicLib::Geocentric(wgs84_a, wgs84_f));
        // // Lat Lon to UTM Map
        // GeographicLib::UTMUPS llutm_map_ = GeographicLib::UTMUPS

        // Parameter
        bool maneuverStarted = false;
        bool vesiDataAvailabe = false;
        bool feedbackDataAvailabe = false;
        bool raptorDataAvailabe = false;
        bool useCustomRaceControl = false;
        bool verbosePrinting = false;
        bool simModeEnabled = false;
        bool numberWarningSent = false;
        uint8_t prestart_rolling_counter;


        // Execution duration logging
        std::vector <double> measured_vesi_times;
        int64_t timeStartNanosec = 0;
        int64_t timeEndNanosec = 0;
        int64_t timeStartVESICallBackNanosec = 0;
        int64_t timeEndVESICallBackNanosec = 0;
        std::ofstream myfile;
        std::string pathTimeRecord;
        bool enableTimeRecord;

        // Simulated clock
        uint32_t nsec = 0;
        uint32_t sec = 0;
        uint64_t simTotalMsec = 0;
        rosgraph_msgs::msg::Clock simClockTime;
        rclcpp::TimerBase::SharedPtr updateSimClock_;

        // Custom publish frequencies
        uint32_t pubIntervalRaceControlData;
        uint32_t pubIntervalVehicleData;
        uint32_t pubIntervalPowertrainData;
        uint32_t pubIntervalGroundTruthArray;
        uint32_t pubIntervalVectorNavData;
        uint32_t pubIntervalNovatelData;
        uint32_t pubIntervalFoxgloveMap;

        // Custom Structures
        VESIResultData feedbackCmds;
        VESIAPI api;
        ASMBus *canBus;
        VESIResultData feedbackCmd;

        void initializeFeedback();

        // Callbacks
        void vesiCallback();
        void simClockTimeCallback();
        void initialSimClockPublish();
        void sendVehicleFeedbackToSimulation();
        void subscribeVehicleCommandsCallback(const autonoma_msgs::msg::VehicleInputs &msg);
        void subscribeRaptorCommandsCallback(const autonoma_msgs::msg::ToRaptor &msg);
        void switchRaceControlSourceCallback(const std_msgs::msg::Bool &msg);
        void simTimeIncreaseCallback(const std_msgs::msg::UInt16 &msg);
        void canSubscriberCallback(Frame::UniquePtr msg);

        // Publishing functions
        void publishFoxgloveMap();
        void publishFoxgloveSceneUpdate();
        void publishSimulationState();
        void publishRaceControlData();
        void publishVehicleData();
        void publishPowertrainData();
        void publishGroundTruthArray();
        void publishVectorNavData();
        void publishNovatelData(uint8_t novatelID);

        //Receiving CAN frames
        void recvBrakePressureCmd(const Frame& msg);
        void recvAcceleratorCmd(const Frame& msg);
        void recvSteeringCmd(const Frame& msg);
        void recvGearShiftCmd(const Frame& msg);
        void recvCtReport(const Frame& msg);


        void publishAllCanData();
        void publishCanDataFromBus(bridge::MessageID can_id);
        std::array<uint8_t, 8> getCanPayload(bridge::MessageID can_id);

        std::string dbw_dbc_file_;
        NewEagle::Dbc dbwDbc_;
    };
}