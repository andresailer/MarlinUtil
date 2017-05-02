#ifndef TRACKAR_H 
#define TRACKAR_H 1

#include "lcio.h"
#include "EVENT/LCIO.h"
#include "EVENT/Track.h"
#include <vector>
#include "ClusterExtended.h"
#include "TrackerHitExtended.h"
#include "GroupTracks.h"

using namespace lcio;

class ClusterExtended;
class GroupTracks;
class TrackerHitExtended;
typedef std::vector<TrackerHitExtended*> TrackerHitExtendedVec;
typedef std::vector<ClusterExtended*> ClusterExtendedVec;

/**
 * Class extending native LCIO class Track. <br>
 * Class TrackExtended is used in TrackwiseClustering <br>
 * and Wolf processors. <br>
 * @author A. Raspereza (DESY)<br>
 * @version $Id: TrackExtended.h,v 1.8 2007-09-05 09:39:49 rasp Exp $<br>
 */

class TrackExtended {

 public:


    TrackExtended( );
    TrackExtended( TrackerHitExtended * trackerhit );
    TrackExtended( Track * track );
    ~TrackExtended();

    //objects do not own pointers, we can use defaults, or they do own and
    //things leak like mad because the dtor is not correctly implemented
    TrackExtended(TrackExtended& trackextended) = default;
    TrackExtended& operator=(TrackExtended& trackextended) = default;

    Track * getTrack();
    const float * getSeedDirection();
    const float * getSeedPosition();
    ClusterExtendedVec & getClusterVec();
    ClusterExtended * getSuperCluster();
    TrackerHitExtendedVec & getTrackerHitExtendedVec();
    void addCluster(ClusterExtended * cluster);
    void setSuperCluster(ClusterExtended * superCluster);
    void setSeedDirection( float * seedDirection );
    void setSeedPosition( float * seedPosition);
    void addTrackerHitExtended( TrackerHitExtended * trackerhit);
    void ClearTrackerHitExtendedVec();

    void setX0(float x0);
    void setY0(float y0);
    void setR0(float r0);
    void setD0(float d0);
    void setZ0(float z0);
    void setBz(float bz);
    void setPhi0(float phi0);
    void setPhi(float phi);
    void setOmega(float omega);
    void setTanLambda(float tanLambda);
    

    void setStart(float * xStart);
    void setEnd(float * xEnd);


    float getX0();
    float getY0();
    float getD0();
    float getZ0();
    float getOmega();
    float getTanLambda();
    float getPhi();
    float getR0();
    float getBz();
    float getPhi0();
    
    float * getStart();
    float * getEnd();

    void setGroupTracks( GroupTracks * group );
    GroupTracks * getGroupTracks();

    float getChi2();
    void setChi2(float chi2);

    int getNDF();
    void setNDF(int ndf);

    float * getCovMatrix();
    void setCovMatrix( float * cov);

 private:

    ClusterExtended *_superCluster;
    ClusterExtendedVec _clusterVec;
    GroupTracks * _group;
    Track * _track;
    float _seedDirection[3];
    float _seedPosition[3];
    TrackerHitExtendedVec _trackerHitVector;    

    float _x0=0.0;
    float _y0=0.0;
    float _r0=0.0;
    float _bz=0.0;
    float _phi0=0.0;

    float _xStart[3];
    float _xEnd[3];

    float _d0=0.0; // d0 in canonical parameterisation
    float _z0=0.0; // z0 in canonical parameterisation
    float _omega=0.0; // omega in canonical parameterisation
    float _tanLambda=0.0; // tanlambda in canonical parameterisation
    float _phi=0.0; // phi in canonical parameterisation

    float _chi2=0.0; // chi2 of the fit

    float _cov[15]; // covariance matrix
    
    int _ndf=0; // NDF
    
};

#endif
