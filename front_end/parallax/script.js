let controller = new ScrollMagic.Controller();
let timeline = new TimelineMax();

timeline
    .to('.logo', 3, {y: 200})
    .to('.logo', 0.4, {opacity: 0}, '-= 3')
    .to('.main-title', 3, {y: 200}, '-=3')
    .to('.main-title', 0.4, {opacity: 0}, '-= 3')
    .to('.content', 3, {top: '-105%'}, '-=3')

let scene = new ScrollMagic.Scene({
    triggerElement: 'section',
    duration: '100%',
    triggerHook: 0,
})
    .setTween(timeline)
    .setPin('section')
    .addTo(controller)