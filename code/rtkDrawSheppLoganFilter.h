/*=========================================================================
 *
 *  Copyright RTK Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

#ifndef __rtkDrawSheppLoganFilter_h
#define __rtkDrawSheppLoganFilter_h

#include <itkInPlaceImageFilter.h>

#include "rtkThreeDCircularProjectionGeometry.h"
#include "rtkSetQuadricParamFromRegularParamFunction.h"

#include <vector>

namespace rtk
{

/** \class DrawSheppLoganFilter
 * \brief Draws a shepplogan phantom using parameters
 *  from http://www.slaney.org/pct/pct-errata.html. Resized to 256x256x256 voxels.
 */

template <class TInputImage, class TOutputImage>
class ITK_EXPORT DrawSheppLoganFilter :
  public itk::InPlaceImageFilter<TInputImage,TOutputImage>
{
public:
  /** Standard class typedefs. */
  typedef DrawSheppLoganFilter                                    Self;
  typedef itk::InPlaceImageFilter<TInputImage,TOutputImage>         Superclass;
  typedef itk::SmartPointer<Self>                                   Pointer;
  typedef itk::SmartPointer<const Self>                             ConstPointer;
  typedef typename TOutputImage::RegionType                         OutputImageRegionType;

  typedef std::vector<double>                                       VectorType;
  typedef std::string                                               StringType;

  typedef rtk::SetQuadricParamFromRegularParamFunction              SQPFunctionType;
  struct figure
  {
    VectorType semiprincipalaxis;
    VectorType center;
    double angle;
    double attenuation;
  };
  /** Method for creation through the object factory. */
  itkNewMacro(Self);

  /** Run-time type information (and related methods). */
  itkTypeMacro(DrawSheppLoganFilter, InPlaceImageFilter);

  /** Get/Set ConfigFile*/
  itkSetMacro(ConfigFile, StringType);
  itkGetMacro(ConfigFile, StringType);

protected:
  DrawSheppLoganFilter() {}
  virtual ~DrawSheppLoganFilter() {};

  virtual void ThreadedGenerateData( const OutputImageRegionType& outputRegionForThread, ThreadIdType threadId );
  /** Translate user parameteres to quadric parameters.
   * A call to this function will assume modification of the function.*/


private:
  DrawSheppLoganFilter(const Self&); //purposely not implemented
  void operator=(const Self&);            //purposely not implemented
  StringType m_ConfigFile;

};

} // end namespace rtk

#ifndef ITK_MANUAL_INSTANTIATION
#include "rtkDrawSheppLoganFilter.txx"
#endif

#endif


