#include <mystd.h>
#include <my_random.h>
#include <my_bin.h>
#include <my_KDCube.h>
#include <my_KDPoint.h>
#include <KDCoordConvert.h>

using namespace MYSTD;
typedef MYMATH::KDPoint3d<int> point_t;             /* Point type in 3-d space */
typedef MYMATH::KDCube3d<const point_t*> cube_t;    /* 3-d Box as a container */

int main(int argc, char const *argv[]){
    /** 
     * prepare `num_points` random data points within a box of side length `xmax`
     * Put them into a 3-d box for fast neighbor searching.
     */
    const int num_points = 100000;
    const double xmax = 100.0;
    vector<point_t> points;
    cube_t cube( xmax, 20 );
    MYMATH::RandomsFloat<> rand(0.0, xmax);             /* random number generator ~ Uniform[0.0, xmax] */
    double x[3];
    for(int i=0; i<num_points; ++i){
        rand.get( x, 3 );
        points.emplace_back( i, x );
    }
    for(const auto &point: points) 
        cube.push_back( point.get_pos(), &point );
    cout << "Generate " << num_points << " data points in box with size = " << xmax << endl;

    /**
     * calculate the two-point correlation function, within radius [0, 10] divided into 20 bins
     */
    const int bin_num = 20;
    const double bin_min = 0.0, bin_step = 0.5;
    MYMATH::ESBin<> bin(bin_min, bin_num, bin_step);    /* convertor from radius to bin id */
    vector<double> corrfunc(bin_num, 0.0);              /* correlation function, 20 bins */
    MYDS::KDCoordConvert3dS coord( xmax, 20 );          /* 3-d distance calculator */

    for(const auto &point: points){
        auto neighbors = cube.get_rect_neighbor_periodic( point.get_pos(), bin_num * bin_step );
        for(const auto &neighbor: neighbors){
            double distance = coord.distance_periodic(point.get_pos(), neighbor->get_pos());
            size_t bin_id;
            if( bin.get_loc2id(distance, bin_id) ) 
                corrfunc[bin_id] += 1.0;
        }
    }
    for(int i=0; i<bin_num; ++i){
        double avg_density = num_points / pow(xmax, 3),
            volume_at_bin = 4.0 / 3.0 * 3.1415926 * ( pow(bin_step*(i+1), 3) - pow(bin_step*i, 3) );
        corrfunc[i] /= num_points * volume_at_bin * avg_density ;
    }

    cout << "Correlation function\n";
    MYFILE::print_range( corrfunc ) << endl;
    MYFILE::array_prt
    return 0;
}
