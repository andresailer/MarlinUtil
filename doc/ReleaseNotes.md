# v01-12-02

# v01-12-01
  - patch release
  - replace LayeredCalorimeter::Layer::thickness
    ( needed for DD4hep v00-18 )

# v01-12

F. Gaede
   - protect against missing SurfaceManager object in DD4hep model
   - updated to use gsl 2.1
   - made compatible with c++11
   - removed -ansi -pedantic -Wno-long-long 

# v01-11

 M.Berggren
  - Added WeightedPoints3D class, a class that analyses a set of points
    in 3 dimensions (possibly with weights), and calculates things like
    covariance matrix, averge position, eigen-vectors/values ...

 F.Gaede
   M /MarlinUtil/trunk/source/src/ClusterShapes.cc
 - merge back changes from version copied to
   MarlinReco for HLR week at Desy:
    - added dummy error functions to ClusterShapes for MarlinPandora development (J.List)
    - cluster shape variables added for mu-pi seaparation (H.Sert)

 T.Quast (RWTH Aachen)
 
   - added DDMarlinCED.cc
     utility and detector draw routines for CEDViewer


# v01-10

    - added helper function in CHT (J.List)
      CHT::CaloType caloTypeFromString(const std::string& name) 

    - fixes in MarlinCED (F.Gaede)
      - fixed warning -Wc++11-narrowing
      - draw inner and outer edge of FTD disks


# v01-09
     - added functions for cluster shape calculation (M. Kurata) 
     - mad compatible for drawing CLIC detector (F.Gaede/M.Petric)

# v01-08-01
     - draw all layers for SIT and SET
       -> draw two layers per double layer

# v01-08
     - improved FPCCD classes (T.Mori)
     - added HelixClass_double 


# v01-07-01
    - added wrapper function (extern "C")
      void draw_helix( ... ) to MarlinCED::drawHelix(...)
       

# v01-07
    - updated code for the ANN library to version 1.1.2 
      (see: http://www.cs.umd.edu/~mount/ANN/ )

    - added helper function to library (extern "C")
      void drawDetectorFromGearFile( const char* fname ) ;

# v01-06-01
    - adopted for multi-module support in MarlinCED for the TPC detector


# v01-06
		- Akiya Miyamoto:
	   implemented flags to turn On and Off geometry of EcalBarrel, EcalEndcap, HcalBarrel, HcalRing, HcalEndcap individually.


# v01-05-03

    - fixed drawing of Hcal endcap (outer radius in gear file)
    - fixed uninitialised variables


# v01-05-02
    
    - bug fix MarlinCED: high pt track straight line was sometimes drawn in wrong direction
    - fixed warnings and made compatible w/ clang++


# v01-05-01

   bug fixes:

       /MarlinUtil/trunk/source/src/MarlinCED.cc:

            - updated for new GEAR attribute getNSensors
            - updated for new definition of FDT sensors (max #2)

            - changed vertex draw method from ced_gebox_r to ced_gebox_r_solid to ensure transparency
       

       /MarlinUtil/trunk/source/src/CalorimeterHitType.cc:

            - changed order of ring and endcap in order to get HcalEndCapRingsCollection as ring layout (reported by G.Grenier)


# v01-05

    - added drawing of the SET
    - added picking print funtions for TrackerHitPlane and TrackerHitZCylinder
    - changed drawing of SIT to 3D shape with surface 
    - modified to match change of MAX_LAYER to CED_MAX_LAYER in ced_cli.h (requires CED 1.4)
    - added plannar SIT and protected against Gear exceptions for missing parameters


# v01-04

    New features:

        - MarlinCED: 
	        - added more subdetectors: FTD, LHCal, LCal, Coil, Yoke, SIT

	        - changed detector colors to match the default colors used in Mokka
     
            - detector components have now layers and layer description

            - Cylinder: inner edges can be different from outeredges, and the inner
                cylinder can be rotated with an other angle as the outer cylinder shape

            - made compatible with CLIC (no LHCal and 11 FTD layers):
               LHCal is now optional and the FTD is drawn dynamically from gear....


         To use the new CED features use CED_GeoTube instead of CED_GeoCylinder.


        - added ILDCellIDEncoding which is needed for development of new tracking
          system, could be removed at a later stage of development

        - header files now installed into subdirectory (marlinutil) to avoid name clashes
            still backwards compatible

        - moved classes FPCCDData and FPCCDPixelHit from MarlinReco
          to MarlinUtil to avoid dependency of Overlay on MarlinReco

    Fixes:
    
        - MarlinCED:
            - old ced_hit_id is now deprecated (the old ced_hit_id used one int to store type and layer number).
	            The new one have one argument more, (layer and type are now 2 fields)
            - Added try/catch blocks to prevent gear::UnknownParameterException, while accessing undefined detector components.
            - fixed drawGEARDetector
            - fixed length of VXD detector ( had used half size only !)
            - allow to toggle visibility of VXD
            - made compatible with new gear (used for ILD_01):
            - use optionally FTDParameters
            - use size of SIT arrays (will have to be changed to ZPlanarLayout)
            - optionally use new coil parameter names



# v01-03

    - Changes (A. Sailer):
        
        - Rewrote the fast HelixClass::getDistanceToPoint

        - Remove unnecessary code from HelixClass:getDistanceToPoint,
            add second getDistanceToPoint function, that stops if distXY is
            larger than given distance, keeps cpu intensive functions from being run.


# v01-02

    - Changes (H. Hoelbe, DESY):
        - Implement remote access to CED:

            * Now you are able to connect to an user defined host and portnumber.

            * Example: To run CED on host "foo" port 7777 and Marlin on host "bar":
                      ssh foo
                      export CED_PORT="7777"
                      glced --trust bar

                      ssh bar
                      export CED_HOST="foo"
                      export CED_PORT="7777"
                      Marlin viewer.xml

    - Simplified cmake scripts
        Improved dependencies:
            - removed dependencies GEAR, LCIO and streamlog (now exported through Marlin)
            - exchanged CMakeModules dependency with new package ILCUTIL


# v01-01

       Changes (H. Hoelbe, DESY):
    -  New methods: MarlinCED::set_layer_description and
       MarlinCED::add_layer_description which stores the 
       layer descriptions and call ced_describe_layer only 
       one time per layer.
    -  Add usleep to the mainloop to avoid busy waiting
       (speed up CED)
    - CalorimeterHitType - added functions:
         CHT::Layout layoutFromString(const std::string& name) ;
         CHT::CaloID caloIDFromString(const std::string& name) ;
      (moved from MarlinReco/LDCCaloDigi/src/CHT_helper)
    - fixed: removed gsl include statements from public header files

# v01-00

     - added support for picking to MarlinCED 
  
     - made compliant w/ gcc 4.4.3 
     
     - made compliant w/ MacOSX


# v00-14-01

    * bug fix: incorrect library version numbers

# v00-14

        * New helper functions for MarlinCED< print(andDraw)MCFamily
        * Header file changes associated with new picking/client-server (as in MarlinCED.cc)
        * src/MarlinCED.cc: SM-H: Added Picking code 
        * Added a (as yet commented out) version of client server communication
        * Changed references to pi = acos(-1) to pi = M_PI
          (Stewart Martin-Haugh)        

# v00-13
    * added helper class CalorimeterHitType for encoding/decoding CalorimeterHit      types (for the ILD detector)

# v00-12
    * added drawing of the VTX detector in drawGEARDetector() [S.Aplin]
    * improved drawing of neutral particles in drawHelix (straight lines)
    * made cmake 2.6 compliant
    * added LIBRARY_DIRS
    * added 32 bit compatibility build option

# v00-11
    * bug fix MarlinCED.h (removed unneeded "#include ced.h" statement)
    * bug fix in CED dependency:
        -> MarMarlinUtilConfig.cmake.in now exports ced_cli.h
        -> needs CED >= v00-05
 
# v00-10
    * removed duplicated code from CED 
      -> made dependant on CED ( >= v00-04-01 ) 
     

# v00-09

    * src/TrackPair.cc: 
      New class used to associate tracks coming from neutral vertices
      (needed by MarlinReco/Tracking/V0Finder) 

# v00-08

    * Updated HelixClass. (A.Raspereza)
      added new  method added which identifies neutral vertices

    * cleaned up code and made gcc4.3 compliant (S.Aplin)

# v00-07
   * removed optional AIDA dependency ( SelectEvents.cc )  J.Engels

   * fixed compiler warnings  J.Samson

   * removed  deprecated HelixClass::getDistanceToHelix()

   * modfied MarlinCED::newEvent to not draw detector for modelID=-1

# v00-06
	* MarlinCED:  modified drawGEARDetector(): incl. Hcal ring/
	  removed overlap Ecal/Hcal (M.Morgunov)

        * Added Circle class: finds a circle from 3 points. Used by TPCDigi. 
          (S.Aplin)

        * improved cmake scriots (J.Engels)

# v00-05
    - improved versions of Track utility classes (A.Raspereza)

    - made compatible with CLHEP 2.0.3.x
        - removed HepPDT dependency

    - added code for writing millipede files 

    - bug fixes:
        -  Doxyfile predefined USE_CLHEP
	-  patched for 64 bit (M.Killenberg)
        - ...

# v00-04
      - cmake now default build tool (J.Engels)
         -> see README for instructions

      - TrackwiseClusters (O.Wendt) 
          improved clustering in 'trajectory coordinates': 
          path-length and distance to trajectory


      - MarlinCED / ced_cli.cc (A.Bulgheroni)
          added drawGEARTelescope
	  added geo_boxes

      - ClusterShapes (O.Wendt) Fixed a bug in FitHelix(int max_iter, int
	  status_out, int parametrisation,float* parameter, float*
	  dparameter, float& chi2,float& distmax, int direction), thanks to
	  Hengne Li @ LAL

      - additional bug fixes 
          + compliance with SL4 (gcc3.4/gcc4)
          + ...

      see Changelog for details 

# v00-03
  - suport for Full Tracking  (A.Raspereza)

  -  suport for TrackBasedPFA (O.Wendt)

  - suport for PhotonFinderKit (P. Krstonosic)

  - first version of Trajectory implementation
    SimpleLine and SimpleHelix (Th. Kraemer)

  - included the ANN (Aproximate Nearest Neighbor) library
    [ see: http://www.cs.umd.edu/~mount/ANN ]

  - added cmake support (epxerimental)
 

 for details see the ChangeLog file


