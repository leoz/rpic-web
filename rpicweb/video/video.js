

var _off = true;

function rpic_cmd_video() {

    _off ? ( _off = false, $(".video_button").text('●') ) :
             ( _off = true, $(".video_button").text('○') );

    $(".video_div").toggle();
}

function rpic_set_video_url() {

    var url = "";
    var port = "3002";
    url = window.location.protocol + "//" + window.location.hostname + ":" + port + "/";

    $('#cam_on').prop('data', url);
}

function scale( width, height, padding, border ) {
    var scrWidth = $( window ).width() - 30,
        scrHeight = $( window ).height() - 30,
        ifrPadding = 2 * padding,
        ifrBorder = 2 * border,
        ifrWidth = width + ifrPadding + ifrBorder,
        ifrHeight = height + ifrPadding + ifrBorder,
        h, w;

    if ( ifrWidth < scrWidth && ifrHeight < scrHeight ) {
        w = ifrWidth;
        h = ifrHeight;
    } else if ( ( ifrWidth / scrWidth ) > ( ifrHeight / scrHeight ) ) {
        w = scrWidth;
        h = ( scrWidth / ifrWidth ) * ifrHeight;
    } else {
        h = scrHeight;
        w = ( scrHeight / ifrHeight ) * ifrWidth;
    }

    return {
        'width': w - ( ifrPadding + ifrBorder ),
        'height': h - ( ifrPadding + ifrBorder )
    };
}

function rpic_set_video_size() {

    var w = 100;
    var h = 100;
    var size = scale( 640, 360, 0, 0 ),
    w = size.width,
    h = size.height;

    $('.video_player').width( w ).height( h );
    $('.video_div').width( w ).height( h );
    $('.video_control').width( w ).height( 40 );
    $('.video_frame').width( w ).height( h );
}

$('#rpic_page_main').live('pageinit', function(event){
    rpic_set_video_size();
    rpic_set_video_url();
});

