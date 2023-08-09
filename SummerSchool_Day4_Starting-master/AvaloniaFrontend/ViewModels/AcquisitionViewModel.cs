using AudioEngineWrapper;
using AvaloniaFrontend.Services;
using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using ScottPlot;

namespace AvaloniaFrontend.ViewModels;

public sealed partial class AcquisitionViewModel : ObservableObject
{
    //TODO #13
    //Add a sample rate
    //Define an Audio Engine

    private const int _sampleRate = 40960;
    private readonly AudioEngineService _audioEngineService = new(_sampleRate, _sampleRate / 5);


    //TODO #16
    //Define CanAcquire property

    [ObservableProperty, NotifyCanExecuteChangedFor(nameof(StopCommand))]
    private bool _canAquire;

    //TODO #14
    //Add constructor to initialize Navigation Service

    public NavigationService NavigationService { get; }
    public AcquisitionViewModel(NavigationService navigationService)
    {
        NavigationService = navigationService;
    }

    //TODO #15
    //Add a ComboBox for Strategy Type (also, in View :)) and a property for the selected strategy type

    public List<AudioStrategyType> AudioStrategyTypes { get; } = Enum.GetValues<AudioStrategyType>().ToList();

    [ObservableProperty]
    private AudioStrategyType _selectedStrategy;

    //TODO #18
    //Create a command that starts the Audio Engine
    //Update the UI plots with audio data
    //Prevent navigation while the audio acquisition is in progress
    //Optionally, plot the FFT 

    //TODO #17
    //Create a command that stops the Audio Engine
    public PlotViewModel TimePlot { get; } = new()
    { Title = "Time Plot" };

    public PlotViewModel FFTPlot { get; } = new()
    { Title = "FFT Plot" };

    private bool StopCanExecute() => _canAquire == true;

    [RelayCommand(CanExecute = nameof(StopCanExecute))]
    public void Stop()
    {
        CanAquire = false;
        _audioEngineService.Stop();

        NavigationService.IsNavigationAllowed = true;
    }

    [RelayCommand]
    public async void Start()
    {
        CanAquire = true;
        _audioEngineService.Start(SelectedStrategy);
        NavigationService.IsNavigationAllowed = false;
        PeriodicTimer periodicTimer = new(TimeSpan.FromMilliseconds(200));

        while (CanAquire)
        {
            await periodicTimer.WaitForNextTickAsync();
            var buffer = _audioEngineService.GetBuffer();
            TimePlot.UpdatePlot(new Models.PlotData()
            {
                SampleRate = _sampleRate,
                YAxis = buffer
            });
            var fft = new FftProcessor().GetMagnitude(_audioEngineService);
            FFTPlot.UpdatePlot(new Models.PlotData()
            {
                SampleRate = 0.2,
                YAxis = fft
            });
            _audioEngineService.ClearBuffer();
        }
    }
}
