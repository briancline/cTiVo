//
//  MTTiVoShow.h
//  cTiVo
//
//  Created by Scott Buchanan on 12/18/12.
//  Copyright (c) 2012 Scott Buchanan. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "iTunes.h"
#import "MTTiVo.h"
#import "MTFormat.h"
#import "mp4v2.h"

@class MTProgramTableView;

@interface MTTiVoShow : NSObject <NSXMLParserDelegate, NSPasteboardWriting,NSPasteboardReading, NSCoding, NSURLDownloadDelegate> {
 }


#pragma mark - Which TiVo did we come from
@property (nonatomic, weak) MTTiVo *tiVo;
@property (nonatomic, strong) NSString *tempTiVoName;  //used before we find TiVo
@property (weak, nonatomic, readonly) NSString *tiVoName; //either of above

//--------------------------------------------------------------
#pragma mark - Properties loaded in from TiVo's XML
@property (nonatomic, strong) NSString 
									*seriesTitle,
									*episodeTitle,
									*showDescription,
									*showLengthString,
                                    *channelString,
                                    *stationCallsign,
									*programId,
									*episodeID,
									*seriesId,
                                    *sourceType,
									*imageString,
                                    *idGuidSource;

//Properties loaded in from TiVo's Detail XML
@property (atomic, strong, readonly) NSString
                                    *episodeNumber,
                                    *movieYear,
                                    *originalAirDate,
                                    *showTime,
                                    *episodeGenre,
                                    *tvRating;
@property (strong, nonatomic, readonly) NSAttributedString
                                    *actors,
                                    *guestStars,
                                    *directors,
                                    *producers;


@property (nonatomic, strong) NSNumber  *protectedShow,  //really BOOLs
										*inProgress,      //Is Tivo currently recording this show
										*isHD;
@property					  double fileSize;  //Size on TiVo;

@property (nonatomic, strong) NSURL *downloadURL,
*detailURL;
@property (atomic, strong) NSString * artworkFile;

@property (nonatomic, strong) NSDate *showDate;
@property					  int    showID;

@property					  time_t showLength;  //length of show in seconds

@property (atomic, strong) NSString *tvdbArtworkLocation;




#pragma mark - Properties loaded in from Details Page
@property int episodeYear;


//--------------------------------------------------------------
#pragma mark - Calculated properties for display 
@property (strong)	NSString *showTitle;  //calculated from series: episode
@property (nonatomic, readonly) NSString *yearString,
										*originalAirDateNoTime,
										 *showDateString,
										*showKey,
										 *showMediumDateString;
@property						int	season, episode; //calculated from EpisodeNumber
@property (weak, nonatomic, readonly) NSString *seasonString;
@property (weak, nonatomic, readonly) NSString *seasonEpisode; // S02 E04 version
@property (readonly, nonatomic) NSString *attribDescription;

@property (nonatomic, readonly) BOOL    isMovie;
@property (nonatomic, readonly) BOOL    isSuggestion;
@property (nonatomic, readonly) NSNumber *channelNumber;  //numeric version of channel. Used only for sorting; NA => big number
@property (weak, nonatomic, readonly) NSString *idString,
										*combinedChannelString,
										*lengthString,
										*isQueuedString,
										*isHDString,
										*sizeString;

@property BOOL isQueued;

@property (nonatomic, assign) BOOL	gotDetails, gotTVDBDetails;

-(void)getShowDetail;

//-(NSArray *) apmArguments;
-(void) setShowSeriesAndEpisodeFrom:(NSString *) newTitle ;

-(void)playVideo:(NSString *)path;
-(void)revealInFinder:(NSArray *)paths;
-(void)getTheTVDBDetails;
-(void)retrieveArtworkIntoFile: (NSString *) filename;


typedef enum {
	HDTypeNotAvailable = -1,
	HDTypeStandard = 0,
	HDType720p = 1,
	HDType1080p = 2
} HDTypes;


-(const MP4Tags * ) metaDataTagsWithImage: (NSImage *) image andResolution:(HDTypes) hdType;


@end
