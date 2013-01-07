

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

    $('#cam_on').prop('src', url);
}

$('#rpic_page_main').live('pageinit', function(event){
    rpic_set_video_url();
});
