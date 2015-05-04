/*!
 *****************************************************************
 * \file
 *
 * \note
 *   Copyright (c) 2010 \n
 *   Fraunhofer Institute for Manufacturing Engineering
 *   and Automation (IPA) \n\n
 *
 *****************************************************************
 *
 * \note
 *   Project name: schunk_modular_robotics
 * \note
 *   ROS stack name: schunk_modular_robotics
 * \note
 *   ROS package name: schunk_powercube_chain
 *
 * \author
 *   Author: Florian Weisshardt, email:florian.weisshardt@ipa.fhg.de
 * \author
 *   Supervised by: Florian Weisshardt, email:florian.weisshardt@ipa.fhg.de
 *
 * \date Date of creation: Dec 2010
 *
 * \brief
 *   Implementation of ROS node for powercube_chain.
 *
 *****************************************************************
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     - Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer. \n
 *     - Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution. \n
 *     - Neither the name of the Fraunhofer Institute for Manufacturing
 *       Engineering and Automation (IPA) nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission. \n
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License LGPL as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License LGPL for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License LGPL along with this program.
 * If not, see <http://www.gnu.org/licenses/>.
 *
 ****************************************************************/

//##################
//#### includes ####
//##################

// standard includes
// --
#include <iostream>
#include <sstream>
#include <string>
#include <deque>
#include <pthread.h> 
#include <schunk_libm5api/m5apiw32.h>

// ROS includes
#include <ros/ros.h>
#include <urdf/model.h>

// ROS message includes
#include <sensor_msgs/JointState.h>
#include <trajectory_msgs/JointTrajectory.h>
#include <control_msgs/JointTrajectoryControllerState.h>
#include <diagnostic_msgs/DiagnosticArray.h>
#include <brics_actuator/JointPositions.h>
#include <brics_actuator/JointVelocities.h>


// ROS service includes
#include <cob_srvs/Trigger.h>
#include <cob_srvs/SetOperationMode.h>

// own includes
#include <schunk_powercube_chain/PowerCubeCtrl.h>
#include <schunk_powercube_chain/PowerCubeCtrlParams.h>
//#include <schunk_powercube_chain/Diagnostics.h>

/*!
 * \brief Implementation of ROS node for powercube_chain.
 *
 * Offers velocity and position interface.
 */

int main(int argc, char** argv)
{
  
  std::cout<<"\n\nTEST THE POWER, MUAHAHAH !\n\n";
  
  int m_DeviceHandle;
  int ret;
  
  std::cout << std::endl << "====================================================== " << std::endl;
  std::ostringstream InitStr;
  InitStr << "PCAN" << ":" << "/dev/pcan34" << "," << "500";
  std::cout << "initstring = " << InitStr.str().c_str() << std::endl;

  
  char strInitString[] = "PCAN:/dev/pcan33,500";
  ret = PCube_openDevice(&m_DeviceHandle, InitStr.str().c_str());
  std::cout<<"[T] done init\n\n";
//   ret = PCube_openDevice(&m_DeviceHandle, strInitString);
  if(ret!=0)  {
    std::cout<<" [T] can't open can device : "<< ret <<"\n\n";
    return 0;
  }
  
  //=============== DO SOME TESTS =====================
  
  int number_of_modules = PCube_getModuleCount(m_DeviceHandle);
  std::cout << "\n\n\n[T] START " << number_of_modules << " modules.\n\n";

  
  //test individual modules
  for(int i=1;i<=6;i++){
    
    unsigned long serNo;
    unsigned short verNo;
    unsigned long defConfig;
    std::vector<std::string> Module_Types; 
    
    ret =  PCube_resetModule(m_DeviceHandle, i);
    if(ret!=0){
      std::cout<<" --- can't reset  module "<< i << " -- err : "<< ret <<"\n";
    }
    else{
      std::cout<<"reset module "<< i << " : "<< serNo <<"\n";
    }
	      
	      
	      
	      
	      
    ret = PCube_getModuleSerialNo(m_DeviceHandle, i, &serNo);
    if(ret!=0){
      std::cout<<" --- can't get serial number from module "<< i << " -- err : "<< ret <<"\n";
    }
    else{
      std::cout<<"serial number from module "<< i << " : "<< serNo <<"\n";
    }
    
    
    
    ret = PCube_getModuleVersion(m_DeviceHandle, i, &verNo);
    if(ret!=0){
      std::cout<<" --- can't get version number from module "<< i << " -- err : "<< ret <<"\n";
    }
    else{
      std::cout<<"module version "<< i << " : "<< serNo <<"\n";
    }
    
    
    
//     ret = PCube_getDefGearRatio(m_DeviceHandle, i, &gear_ratio);
      
    
  }
  std::cout << "\nEND " << number_of_modules << " modules." << std::endl;
  
  
  ret = PCube_closeDevice(m_DeviceHandle);
//   ret = PCube_openDevice(&m_DeviceHandle, InitStr.str().c_str());
  if(ret!=0)  {
    std::cout<<"can't close device : "<< ret <<"\n\n";
    return 0;
  }
  
//   pthread_mutex_unlock(&m_mutex);
  
  

  return 0;
}
